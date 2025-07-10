#include "game.h"
#include <bits/stdc++.h>
using namespace std;
vector<bool> act;
vector<int> arr, single, sz;
set<int> alr;
int n; 
void unite(int a, int b){
    int elotrob = arr[b];
    a = arr[a];
    sz[a] += sz[b];
    for(int i = 0; i < n; i++){
        if(arr[i] == elotrob){
            arr[i] = a;
        }
    }
}

void initialize(int N) {
    n = N;
    act.assign(n, 0);
    sz.assign(n, 1);
    arr.assign(n, 0);
    single.assign(n, -1);
    iota(arr.begin(), arr.end(), 0);
}

int hasEdge(int u, int v) {
    cout << "----------------------------" << endl;
    for(const int &i : arr){ cout << i << " "; }
    cout << endl;
    for(const int &i : single){ cout << i << " "; }
    cout << endl;
    u = arr[u];
    v = arr[v];
    if(!act[u] and !act[v]){
        unite(u, v);
        act[u] = act[v] = 1;
        int x = max(single[u], 0) + max(single[v], 0);
        single[u] = 0;
        for(int i = 0; i < n; i++){
            if(u != i and v != i){
                single[u] += 2;
            }
        }
        single[u] -= x;
        alr.insert(u);
        return 1;
    }
    if(act[u] and act[v]) {
        single[u]--;
        single[v]--;
        if(single[u] and single[v]) return 0;
        single[u] += single[v];
        alr.erase(v);
        unite(u, v);
        return 1;
    }
    if(act[u] and !act[v]) swap(u, v);
    if(single[u] == -1){
        single[u] = 0;
        for(const int &x : alr){
            single[u] += sz[x];
        }
    }
    single[u]--;
    single[v]--;
    if(!single[u] or !single[v]){
        act[u] = 1;
        unite(v, u);
        single[v] += single[u];
        for(int i = 0; i < n; i++){
            if(!act[i]) {
                single[v] += 2;
            }
        }
        for(int i = 0; i < n; i++){
            if(single[i] != -1 and !act[i]){
                single[i]++;
            }
        }
        return 1;
    }
    return 0;
}
