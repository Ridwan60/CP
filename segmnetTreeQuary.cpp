#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INTEGER_MAX 9999999999

vector < ll > tree;

ll getMin(ll node, ll node_left, ll node_right, ll query_left, ll query_right)
{
	if(node_left>=query_left && node_right<=query_right ){
		return tree[node];
	}

	if(node_right < query_left || node_left > query_right ){
		return INTEGER_MAX;
	}
	ll mid = (node_left + node_right) / 2; 
	ll x = getMin(node*2, node_left, mid, query_left, query_right);
	ll y = getMin(node*2 + 1, mid+1, node_right, query_left, query_right);
	return min( x , y );
}


int main()
{
	ll n, q;
	cin >> n >> q;
	vector < ll > a(n);

	for( int i = 0 ; i < n ; i++ ){
		cin>> a[i];
	}

	while(__builtin_popcount(n)!=1){
		n++;
		a.push_back(INTEGER_MAX);
	}

	tree.resize(2*n);

	for( int i = 0 ; i < n ; i++ ){
		tree[n+i] = a[i];
	}

	for( int i = n-1 ; i>=1 ; i--){
		tree[i] = min(tree[ 2*i ] , tree[ 2*i + 1]);
	}

	/*for(int i = 1 ; i < 2*n ; i++ ){
		cout << tree[i] << ' ';
	}
	cout << endl;*/

	while(q--){
		ll query_left, query_right;
		cin >> query_left >> query_right;
		query_left--;
		query_right--;

		cout << getMin(1, 0, n-1, query_left, query_right) << endl;
	}

}
