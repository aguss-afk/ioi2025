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
    string x, y = "ADVITIYA";
    cin >> x;
    int ans = 0;
    for(int i = 0; i < 8; i++){
        if(x[i] == y[i]){
            continue;
        }
        if(x[i] < y[i]){
            ans += y[i] - x[i];
            continue;
        }
        ans += 'Z' - x[i] + y[i] - 'A' + 1;
    }
    cout << ans << '\n';
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
