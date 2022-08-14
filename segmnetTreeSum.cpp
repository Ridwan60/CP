#include <bits/stdc++.h>
using namespace std;

#define ll long long

std::vector < ll > tree;

ll getSum ( ll node, ll node_left, ll node_right, ll query_left, ll query_right )
{
	if( node_left >= query_left && node_right <= query_right ) {
		return tree[node];
	}

	if( node_left > query_right || node_right < query_left ) {
		return 0;
	}

	ll mid = (node_left + node_right) / 2;

	ll sum = getSum( 2*node, node_left, mid, query_left, query_right) + 
			getSum( 2*node+1, mid + 1, node_right, query_left, query_right);

	return sum;
}

int main()
{
	ll n, q;
	std::cin >> n >> q;
	std::vector < ll > a(n);
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[i];
	}

	while( __builtin_popcount(n) != 1 ) {
		n++;
		a.push_back(0);
	}

	tree.resize(2*n);

	for( int i = 0; i < n; i++ ) {
		tree[n+i] = a[i];
	}
	for( int i = n-1; i >= 1; i-- ) {
		tree[i] = tree[2*i] + tree[2*i+1];
	}

	while( q-- ) {
		ll q_left, q_right;
		std::cin >> q_left >> q_right;
		q_left--;
		q_right--;
		std::cout << getSum(1, 0, n-1, q_left, q_right) << endl;
	}
}
