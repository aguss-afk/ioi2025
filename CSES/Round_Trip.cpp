#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> arr;
vector<int> ans;
vector<bool> vis;
bool dfs(int a, int parent){
    if(vis[a]){
        bool t = 0;
        int size = 0;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == a){
                cout << ans.size() - i + 1 << "\n";
                t = 1;
            }
            if(t){
                cout << ans[i] + 1 << " ";
            }
        }
        cout << a + 1;
        return 1;
    } else if(vis[a]){
        return 0;
    }
    vis[a] = 1;
    ans.push_back(a);
    for(const int x : arr[a]){
        if(x != parent and dfs(x, a)){
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    arr.assign(n, vector<int>(0));
    vis.assign(n, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bool ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].size() and !vis[i] and dfs(i, -1)){
            ans = 1;
            break;
        }
    }
    if(!ans){
        cout << "IMPOSSIBLE";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
