#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
vector<vector<int>> arr;
vector<int> dp;
int dfs(int a){
    if(dp[a] != -1){
        return dp[a];
    }
    int c = 0;
    for(int &i : arr[a]){
        c = max(c, dfs(i));
    }
    return dp[a] = c + 1;
}

void solve(){
    int n, m;
    cin >> n >> m;
    arr.assign(n, vector<int>(0));
    dp.assign(n, -1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == -1){
            ans = max(ans, dfs(i));
        }
        //dbgv(dp);
    }
    cout << ans - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
