#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<vector<int>> arr;
vector<bool> vis;
ll x, edges;
void dfs(int a){
    if(vis[a]){
        return;
    }
    vis[a] = 1;
    x++;
    edges += arr[a].size();
    for(int x : arr[a]){
        dfs(x);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    arr.assign(n, vector<int>(0));
    vis.assign(n, 0);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            x = 0;
            edges = 0;
            dfs(i);
            if(x * (x - 1) != edges){
                cout << "NO";
                return;
            }
        }
    } 
    cout << "YES";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
