/*		BISMILLAHIR-RAHMANIR-RAHIM
			  MichaelScott
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> bfsOfGraph(int nodeNo, vector<int> adj[]){
	vector<int> bfs; // it would output a sequenced vector
	vector<int> vis(nodeNo+1, 0); // for checking if the visiting node is already visited or not

	for(int i = 1; i <= nodeNo; i++){
		if(!vis[i]){
			queue<int> q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				// cout<<node<<endl ;
				bfs.push_back(node);

				for(auto it : adj[node]){
					if(!vis[it]){
						q.push(it);
						vis[it]=1;
					}
				}
			}
		}
	}
	return bfs;
}

int main()
{
	int nodeNo, edgeNo;
	cin >> nodeNo >> edgeNo;
	vector<int> adj[nodeNo+1];

	for(int i = 0; i < nodeNo; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> bfs = bfsOfGraph(nodeNo, adj);
	for(int i = 0 ; i < bfs.size(); i++){
		cout << bfs[i]<<" ";
	}
	
	return 0;
}
// Alhamdulillah
