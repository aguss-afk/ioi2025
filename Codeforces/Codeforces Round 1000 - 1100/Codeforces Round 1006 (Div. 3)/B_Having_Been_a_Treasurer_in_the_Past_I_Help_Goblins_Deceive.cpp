#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n;
    cin >> n;
    string j;
    cin >> j;
    int a = 0;
    for(char &i : j){
        if(i == '-'){
            a++;
        }
    }
    if(a < 2 or n == a){
        cout << 0 << '\n';
        return;
    }
    ll x = n - a;
    ll y = a / 2;
    n = a;
    ll z = n - y;
    ll ans = y * x * z;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
