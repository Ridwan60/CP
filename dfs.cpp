/*		BISMILLAHIR-RAHMANIR-RAHIM
			  MichaelScott
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*vector<int> dfs(int node,vector<int> vis, vector<int> adj[], vector<int> strDFS){
	strDFS.push_back(node);
	// cout << node << " " ;
	vis[node] = 1;

	for(auto it : adj[node]){
		if(vis[it] != 1){
			return dfs(it, vis, adj, strDFS);
		}
	}
	// cout << endl;
	return strDFS;
	
}

vector<int> dfsofGraph(int nodeNo, vector<int>adj[]){
	vector<int> vis(nodeNo+1, 0);
	vector<int> strDFS;

	for(int i = 1; i <= nodeNo; i++){

		if(vis[i] != 1){
			// 	cout << i << "->";
			dfs(i, vis, adj, strDFS);
		}
	}
	return strDFS;
}
*/

vector<bool>vis ;
vector<int>ans ;
map<int,vector<int> > mp ;

void dfs(int source){
	vis[source]=1 ;

	for(auto x:mp[source]){
		if(!vis[x])
			dfs(x);
	}
	ans.push_back(source) ;
}

int main()
{
	ans.clear() ;
	mp.clear() ;
	int nodeNo, edgeNo;
	cin >> nodeNo >> edgeNo;
	
	
	// int n=nodeNo ;

	vis.resize(nodeNo+1) ;
	

	for(int i=1 ; i<=nodeNo ; i++ )
		vis[i]=false ;

	for(int i = 1 ; i <= nodeNo; i++){
		int u, v;
		cin >> u >> v;
		mp[u].push_back(v);
	}

	for(int i=1 ; i<=nodeNo ; i++){
		if(!vis[i]){
			dfs(i) ;
		}
	}
	// reverse(ans.begin(),ans.end()) ;

	for(auto x: ans)cout<<x<<" " ;
		cout<<endl ;
	return 0;
}
// Alhamdulillah
