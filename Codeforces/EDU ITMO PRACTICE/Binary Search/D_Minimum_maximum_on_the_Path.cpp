#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<vector<pair<int, int>>> arr;
int n, d, ans2;

int dfs(int m, int i, int currsiz){
    dbg(i);
    if(i == n){
        return currsiz + 1;
    }
    int a = MOD;
    for(auto &[x, y] : arr[i]){
        if(y <= m){
            a = min(dfs(m, x, currsiz + 1), a);
        }
    }
    return a;
}

void solve(){
    int m;
    cin >> n >> m >> d;
    arr.assign(n, vector<pair<int, int>>(0));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr[a].push_back({b, c});
    }
    int l = 0, r = 1e9;
    while(l + 1 < r){
        int m = l + (r - l) / 2;
        if(dfs(m, 1, 1) <= d + 1){
            r = m;
            continue;
        } 
        l = m + 1;
    }
    cout << m << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
