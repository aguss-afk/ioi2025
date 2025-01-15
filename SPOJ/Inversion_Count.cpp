#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct bit {
    vector<ll> arr;
    int n;
    bit(int n) : n(n){
        arr.assign(n + 1, 0);
    }
    void update(int a, int b){
        while(a <= n){
            arr[a] += b;
            a += a & (-a);
        }
    }
    ll add(int a){
        ll res = 0;
        while(a > 0){
            res += arr[a];
            a -= a & (-a);
        }
        return res;
    }
};
void solve(){
    int n;
    cin >> n;
    bit fen(n);
    ll ans = 0;
    vector<int> arr, q;
    map<int, int> pos;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
        q.push_back(a);
    }
    sort(all(arr));
    for(int i = 0; i < n; i++){
        pos[arr[i]] = i;
    }
    reverse(all(q));
    for(int x : q){
        ans += fen.add(pos[x] + 1);
        fen.update(pos[x] + 1, 1);
    }
    cout << ans << "\n";
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
