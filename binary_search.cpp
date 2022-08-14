/*		BISMILLAHIR-RAHMANIR-RAHIM
			  MichaelScott
*/
#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 9;
int a[N];
#define ll long long


bool search(int l, int r, int x){
	
	if(l > r) 
		return false;

	int mid = (l+r) / 2;
	
	if(a[mid] == x) 
		return true;
	else if(a[mid] > x){
		return search(l, mid-1, x);
	}
	else{
		return search(mid+1, r, x);
	}
}

int main()
{
	int n, q;
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	// std::cin >> t;
	while( q-- ) {
		int x, l = 0, r = n-1;
		cin >> x;
		bool ok = search(l, r, x);

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}
// Alhamdulillah
