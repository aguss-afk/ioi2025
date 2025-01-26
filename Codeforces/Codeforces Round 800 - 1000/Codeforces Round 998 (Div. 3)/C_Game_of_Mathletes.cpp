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
    vector<int> arr(n);
    map<int, int> m1, m2;
    for(int &x : arr){
        cin >> x;
        m1[x]++;
    } 
    ll ans = 0;
    for(auto x : m1){
        if(m1.count(k - x.first)){
            ll a = min(m1[k - x.first], x.second);
            ans += a;
        }
    }
    cout << ans / 2 << '\n';
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
