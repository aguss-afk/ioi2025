#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    int y = (abs(k) + p - 1) / p;
    dbg(y);
    if(y > n){
        cout << -1 << "\n";
        return;
    }
    cout << y << "\n";
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
