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
    int a, b, c, d, ans = 1;
    cin >> a >> b >> c >> d;
    int ans2 = 0;
    for(int i = -1000; i <= 1000; i++){
        ans = 0;
        if(i == a + b) ans++;
        if(c == i + b) ans++;
        if(d == i + c) ans++;
        ans2 = max(ans2, ans);
    }
    cout << ans2 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
