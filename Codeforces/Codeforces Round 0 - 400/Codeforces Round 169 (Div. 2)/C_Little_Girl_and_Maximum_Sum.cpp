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
    int n, c;
    cin >> n >> c;
    vector<ll> arr(n), prefsum(n + 2);
    for(ll &i : arr){
        cin >> i;
    }
    for(int i = 0; i < c; i++){
        ll a, b;
        cin >> a >> b;
        prefsum[a] += 1;
        prefsum[b + 1] -= 1;
    }
    vector<ll> maxis;
    for(int i = 1; i < n + 1; i++){
        prefsum[i] += prefsum[i - 1];
        maxis.push_back(prefsum[i]);
    }
    sort(rall(maxis));
    sort(rall(arr));
    ll ans = 0;
    for(int i = 0; i < n ; i++){
        ans += arr[i] * maxis[i];
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
