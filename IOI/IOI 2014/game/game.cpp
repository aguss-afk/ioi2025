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
