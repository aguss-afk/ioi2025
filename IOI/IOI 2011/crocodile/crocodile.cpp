#include "crocodile.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<vector<pair<ll, ll>>> arr;
set<int> p;
vector<ll> dis;
vector<bool> vis;
void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    dis[0] = 0;
    while(!q.empty()){
        ll node = q.top().second;
        q.pop();
        if(vis[node]){
            continue;
        }
        vis[node] = 1;
        for(auto [x, y] : arr[node]){
            if(dis[node] + y < dis[x]){
                dis[x] = dis[node] + y;
                q.push({dis[x], x});
            }
        }
    }
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
    arr.assign(N, vector<pair<ll, ll>>(0));
    dis.assign(N, INF);
    vis.assign(N, 0);
    for(int i = 0; i < K; i++){
        p.insert(P[i]);
    }
    for(int i = 0; i < M; i++){
		arr[R[i][0]].push_back({R[i][1], L[i]});
		arr[R[i][1]].push_back({R[i][0], L[i]});
    }
    dijkstra();
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(p.count(i)){
            ans = max(dis[i], ans);
        }
    }
    return ans;
}


