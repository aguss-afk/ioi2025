#include "crocodile.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<vector<pair<ll, ll>>> arr;
vector<pair<ll, ll>> dis;
vector<bool> vis;
vector<ll> exits;
void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for(ll &i : exits){
        q.push({0, i});
        dis[i] = {0, 0};
    } 
    while(!q.empty()){
        int actnode = q.top().second;
        q.pop();
        if(vis[actnode]){
            continue;
        }
        vis[actnode] = 1;
        for(auto &[x, y] : arr[actnode]){
            if(dis[actnode].second + y < dis[x].first){
                if(dis[x].first < dis[x].second){
                    dis[x].second = dis[x].first;
                }
                dis[x].first = dis[actnode].second + y;
            } else if(dis[actnode].second + y < dis[x].second){
                dis[x].second = dis[actnode].second + y;
            }
            if(dis[x].second != INF){
                q.push({dis[x].second, x}); 
            }
        }
    } 
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
    arr.assign(N, vector<pair<ll, ll>>(0));
    dis.assign(N, {INF, INF});
    vis.assign(N, 0);
    for(int i = 0; i < M; i++){
        arr[R[i][0]].push_back({R[i][1], L[i]});
        arr[R[i][1]].push_back({R[i][0], L[i]});
    }
    for(int i = 0; i < K; i++){
        exits.push_back(P[i]);
    }
    dijkstra();
    return dis[0].second;
}
