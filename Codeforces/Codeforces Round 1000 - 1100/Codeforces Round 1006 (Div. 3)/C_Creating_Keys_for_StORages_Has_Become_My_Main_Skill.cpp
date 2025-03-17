#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    if(a == 1){
        cout << b << '\n';
        return;
    }
    int y = 0;
    for(int i = 0; i < a - 1; i++){
        int j = b | i;
        if(j == b){
            ans |= i;
            int x = b | i;
            cout << i << ' ';
            y++;
            continue;
        }
        break;
    }
    int j = ans | (a - 1);
    if(a - y == 1 and j == b){
        cout << a - 1 << '\n';
        return;
    }
    for(int i = 0; i < a - y; i++){
        cout << b << ' ';
    }
    cout << '\n';
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
