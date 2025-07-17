#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;
vector<int> arr;
vector<vector<pair<int, long long>>> mst, nmst;
vector<pair<long long, pair<int, int>>> edges;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
int finder(int a){
    return arr[a] = (arr[a] == a ? a : finder(arr[a]));
}
void unite(int a, int b){
    a = finder(a);
    b = finder(b);
    if(a == b) return;
    arr[a] = b;
}
void solve(){
    int n, m;
    cin >> n >> m;
    arr.assign(n, 0);
    mst.assign(n, vector<pair<int, long long>>(0));
    nmst.assign(n, vector<pair<int, long long>>(0));
    iota(arr.begin(), arr.end(), 0);
    for(int i = 0; i < m; i++){
        long long a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
        q.push({w, i});
        a--, b--;
        if(i < n - 1){
            nmst[a].push_back({b, w});
            nmst[b].push_back({a, w});
        }
    }
    while(!q.empty()){
        pair<long long, int> act = q.top();
        q.pop();
        int a = edges[act.second].second.first;
        int b = edges[act.second].second.second;
        if(finder(a) != finder(b)){
            unite(a, b);
            mst[a].push_back({act.first, b});
            mst[b].push_back({act.first, a});
        }
    }
    for(int i = 0; i < n; i++){
        if(mst[i].size()){
            for(auto &x : mst[i]){
                cout << i << ' ' << x.first << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
