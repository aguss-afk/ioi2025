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
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    if(k == n){
        for(int i = 1; i < n; i += 2){
            if(arr[i] != (i + 1) / 2){
                cout << (i + 1) / 2 << '\n';
                return;
            }
        }
        cout << (k / 2) + 1 << '\n';
        return;
    }
    for(int j = 1; j < n + 2 - k; j++){
        if(arr[j] != 1){
            cout << 1 << '\n';
            return;
        }
    }
    if(n + 1 - k > 1){
        cout << 2 << '\n';
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
