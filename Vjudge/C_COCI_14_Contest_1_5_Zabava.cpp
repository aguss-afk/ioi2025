#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    ll lim = (n + k) / (k + 1), ans = 0, aux = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        aux++;
        ans += aux;
        if(aux == lim and i != n - 1){
            k--;
            lim = (n - i - 1 + k) / (k + 1);
            aux = 0;
        }
    }
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
