#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

vector<vector<int>> arr;
vector<bool> vis;
ll dfs(int currnode, int mid){
    ll diff = mid;
    for(int i : arr[currnode]){
        if(vis[i]){
            continue;
        }
        vis[i] = 1;
        diff += dfs(i, mid) - 1;
    }
    return min(0ll, diff);
}

void solve(){
    int n;
    cin >> n;    
    arr.assign(n, vector<int>(0));
    vis.assign(n, 0);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    ll l = 0, r = MOD, ans = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        vis.assign(n, 0);
        vis[0] = 1;
        if(!dfs(0, m)){
            ans = m;
            r = m - 1;
            continue;
        }
        l = m + 1;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}