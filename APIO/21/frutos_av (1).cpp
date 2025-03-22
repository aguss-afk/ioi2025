#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbgv(x) cerr << #x << ": "; for(auto &i : x) cerr << i << ' '; cerr << "\n";
#define dbg(x) cerr << #x << ": " << x << '\n';
ll ans;
vector<ll> val;
vector<vector<ll>> arr;
vector<pair<ll, ll>> dp;
pair<ll,  ll> dfs1(int curr,  int dep, int prev){
    dp[curr] = {val[curr] * dep, val[curr]};
    for(ll &i : arr[curr]){
        if(i != prev){
            pair<int, int> ans = dfs1(i, dep + 1, curr);
            dp[curr].first += ans.first;
            dp[curr].second += ans.second;
        }
    }
    return dp[curr];
}

void dfs2(int curr, ll father_first, ll father_second, int prev){
    //dbg(ans);
    //ff = father_first - dp[curr].first * 2 + dp[curr].first + fs - dp[curr].second;
    ll fs = 0;
    for(ll &i : arr[curr]){
        if(i == prev) continue;
        fs += dp[i].second;
    }
    ll ff = father_first - val[curr] - fs + father_second;
    /* dbg(ff);
    dbg(fs);
    dbg(curr); */
    ans = max(ans, ff);
    for(ll &i : arr[curr]){
        if(i == prev) continue;
        dfs2(i, ff, father_second + dp[curr].second - dp[i].second, curr);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    arr.assign(n, vector<ll>());
    val.assign(n, 0);
    dp.assign(n, pair<ll, ll>());
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    dfs1(0, 1, 0);
    /* for(int i = 0; i < n; i++){
        cout << dp[i].first << ' ' << dp[i].second << '\n';
    } */
    ans = dp[0].first;
    for(ll &i : arr[0]){
        dfs2(i, dp[0].first, dp[0].second - dp[i].second, 0);
    }
    cout << ans;
}