#include "game.h"
#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << "\n";
using namespace std;
int n;
set<int> x;
vector<int> arr, siz, activado;
map<int, int> single, grupal;
void join(int a, int b){
    int u = arr[b];
    for(int i = 0; i < n; i++){
        if(arr[i] == u){
            siz[a]++;
            arr[i] = arr[a];
        }
    }

}
void initialize(int N) {
    n = N;
    arr.assign(n, 0);
    iota(arr.begin(), arr.end(), 0);
    activado.assign(n, 0);
    siz.assign(n, 1);
}

int hasEdge(int u, int v) {
    if(!activado[u] and !activado[v]){
        activado[u] = 1;
        activado[v] = 1;
        int couenta = 0;
        for(int i = 0; i < n; i++){
            if(!activado[i]){
                couenta++;
            } 
        }
        if(single.count(v)){
            single[u] += single[v];
        }
        single[u] += 2 * couenta;
        join(u, v);
        x.insert(u);
        return 1;
    } 
    if(activado[u] and !activado[v]) swap(u, v);
    dbg(u);
    dbg(v);
    u = arr[u];
    v = arr[v];
    if(!single.count(u)){
        for(const int &i : x){
            single[u] += siz[i];
        }
    }
    dbg(single[u]);
    dbg(single[v]);
    single[u]--;
    single[v]--;
    if(single[u] == 0 or single[v] == 0){
        join(v, u);
        if(!activado[u]){
            for(int i = 0; i < n; i++){
                if(!activado[i] and single.count(i)){
                    single[i]++;
                }
            }
        }
        activado[u] = 1;
        return 1;
    }
    return 0;
}
