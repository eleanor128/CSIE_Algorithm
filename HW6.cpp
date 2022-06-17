#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <limits.h>
#include <queue>
#include <bits/stdc++.h>
using std::string;
using namespace std;

int n;
vector<vector<int>> limit0,limit_2;

bool BFS(int s, int sink, int parent[], vector<int> adj[]){
	
	bool visited[n];
  	memset(visited, 0, sizeof(visited));

  	queue<int> Q;
  	Q.push(s);
  	visited[s] = true;
  	parent[s] = -1;

  	while (!Q.empty()) {
    	int u = Q.front();
    	Q.pop();

    	for(auto& v: adj[u]){
      		if(visited[v] == false && limit_2[u][v] > 0){
        		Q.push(v);
        		parent[v] = u;
        		visited[v] = true;
        		if(v == sink){
        			return true;
				}
      		}
    	}
  	}
	
	return false;
}

int Ford(int s, int sink, vector<int> adj[]){

  	int u, v;
	int parent[n];
  	int max_flow = 0; 
    
  	while (BFS(s, sink, parent, adj)){

	    for(v=sink; v!=s; v=u) {
	      	u = parent[v];
	      	limit_2[u][v] -- ;
	      	limit_2[v][u] ++ ;
	    }
    	max_flow ++;
  	}
	return max_flow;
}


int main() {

	int u,v;
	cin >> n; // 有n個點 
	int ans=INT_MAX;

	vector<int> s;
	s.assign(n, 0);

	limit0.assign(n,s);
	limit_2.assign(n,s);
	vector<int> adj[n];

	while(cin >> u >> v){
		limit0[u][v] = 1;
		limit0[v][u] = 1;
		limit_2[u][v] = 1;
		limit_2[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int sink=1; sink<n; sink++){ 
		ans = min(ans,Ford(0,sink, adj));

		for(int i=0; i<n; i++){
			limit_2[i] = limit0[i];
		}
	}
	cout << ans;
}
