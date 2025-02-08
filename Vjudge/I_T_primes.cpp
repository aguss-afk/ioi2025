#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;
vector<bool> criba(1e6 + 1, 1);
void calc(){
    criba[0] = criba[1] = 0;
    for(ll i = 2; i < 1e6 + 1; i++){
        if(criba[i] and i * i <= 1e6){
            for(ll j = i * i; j < 1e6 + 1; j += i){
                criba[j] = 0;
            }
        }
    }
}
void solve(){
    ll n;
    cin >> n;    
    double x = (sqrt(n));
    if(floor(x) != ceil(x) or !criba[x]){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    calc();
    while(t--){
        solve();
    }
}
