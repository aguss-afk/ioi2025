#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<unordered_set<int>> graph;
vector<bool> vis;
void Init(int N_) {
  	n = N_;
	graph.assign(n, unordered_set<int>(0));
}

void Link(int a, int b) {
	graph[a].insert(b);
	graph[b].insert(a);
}

bool dfs(int node, int parent, int toerase){
    for(auto x : graph[node]){
        if(x == toerase){
            continue;
        }
        if(graph[x].size() - graph[x].count(toerase) > 2){ 
            return 0;
        }
        if(vis[x]){
            if(x == parent){
                continue;
            }
            return 0;
        }
        vis[x] = 1;
        bool ans = dfs(x, node, toerase);
        if(!ans){
            return 0;
        }
    }
    return 1;
}

int CountCritical() {
	vis.assign(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool t = 1;
        for(int j = 0; j < n; j++){
            if(j == i){
                continue;
            } 
            if(!vis[j]){
                vis[j] = 1;
                if(!dfs(j, -1, i)){
                    t = 0;
                	break;
                }
            }
        }
        if(t){
            ans++;
        }
        vis.assign(n, 0);
 
    }
	return ans;
}
