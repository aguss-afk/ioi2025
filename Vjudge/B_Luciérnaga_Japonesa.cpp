#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n, m, x, ans = MOD, ans2;
    cin >> n >> m;
    vector<ll>  obs(m + 2);
    for(int i = 0; i < n; i++){
        cin >> x;
        if(i & 1){
            obs[m + 1 - x]++;
            obs[m + 1]--;
            continue;
        } 
        obs[1]++;
        obs[x + 1]--;
    }
    for(int i = 1; i <= m; i++){
        obs[i] += obs[i - 1];
        if(ans > obs[i]){
            ans = obs[i];
            ans2 = 1;
            continue;
        }
        if(ans == obs[i]){
            ans2++;
        }
    }
    cout << ans << " " << ans2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}