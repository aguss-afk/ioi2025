#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    ll n, m;
    cin >> n >> m;
    if(n >= m){
        cout << n << '\n';
        return;
    }
    if(n * 2 <= m){
        cout << "0\n";
        return;
    }
    cout << 2 * n - m << '\n';
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
