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
void solve(){
    int n, m;
    cin >> n >> m;    
    vector<vector<pair<int, int>>> arr(n);
    vector<vector<ll>> dij(n, vector<ll>(1001, INF)), vis(n, vector<ll>(1001, 0));
    vector<ll> s(n);
    f2(i, m, 0){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    f1(i, s){
        cin >> i;
    }
    priority_queue<vector<ll>> q;
    q.push({0, s[0], 0});
    dij[0][s[0]] = 0;
    while(!q.empty()){
        ll b = q.top()[1];
        ll a = q.top()[2];
        q.pop();
        if(vis[a][b]){
            continue;
        }
        vis[a][b] = 1;
        for(const auto [x, y] : arr[a]){
            ll best = min(b, s[x]);
            if(dij[a][b] + b * y < dij[x][best]){
                dij[x][best] = dij[a][b] + b * y;
                q.push({-dij[x][best], best, x});
            }
        }
    }
    ll ans = INF;
    f1(i, dij[n - 1]){
        ans = min(ans, i);
    }
    cout << ans << endl;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
