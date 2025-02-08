#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    ll x, y;
    cin >> x >> y;
    if(x >= y){
        cout << "YES" << '\n';
        return;
    }
    map<ll, bool> vis;
    while(1){
        if(vis[x]){
            cout << "NO\n";
            return;
        }
        vis[x] = 1;
        if(x % 2 and x > 1){
            x--;
        }
        vis[x] = 1;
        x *= 3;
        x /= 2; 
        if(x >= y){
            cout << "YES\n";
            return;
        }
    }
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
