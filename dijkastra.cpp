/*		BISMILLAHIR-RAHMANIR-RAHIM
			  MichaelScott
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int, int>> g[N];
void djkstra(int source){
	vector<int> distance(N, INF);
	vector<int> visited(N, 0);
	distance[source] = 0;
	
	set<pair<int, int>> st;
	st.insert({0, source});
	
	while(st.size() > 0){
		auto node = *st.begin();
		int a = node.second;
		int a_wth = node.first;
		if(visited[a] == 1) continue;
		visited[a] = 1;
		for(auto chid : g[a]){
			int child_a = child.first;
			int child_wth = child.second;
			if(distance[a]+child_wth < distance[child_a]){
				distance[child_a] = distance[a]+child_wth;
				st.insert({distance[child_a], child_a});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i = 0 ; i < m; i++){
		int x, y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y, wt});
	}
	return 0;
}
