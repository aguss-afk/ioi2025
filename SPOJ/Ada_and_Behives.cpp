#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct fenwick_tree_2d {
    vector<vector<ll>> bit;
    int n, m;
    fenwick_tree_2d(int n, int m) : n(n), m(m){
        bit.assign(n + 1, vector<ll>(m + 1, 0));
    }
    void update(ll a, ll b, ll c){
        for(int i = a; i <= n; i += i & (-i)){
            for(int j = b; j <= m; j += j & (-j)){
                bit[i][j] += c;
            }
        }
    }
    ll getsum(ll a, ll b){
        ll res = 0;
        for(int i = a; i > 0; i -= i & (-i)){
            for(int j = b; j > 0; j -= j & (-j)){
                res += bit[i][j];
            }
        }
        return res;
    }
    ll getsum(ll i1, ll j1, ll i2, ll j2){
        return getsum(i1, j1) - getsum(i2 - 1, j1) - getsum(i1, j2 - 1) + getsum(i2 - 1, j2 - 1);
    }
};
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    fenwick_tree_2d bit(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            bit.update(i + 1, j + 1, a);
        }
    }
    while(q--){
        int t;
        cin >> t;
        if(t - 1){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << bit.getsum(c, d, a, b) << "\n";
            continue;
        } 
        int a, b, c;
        cin >> a >> b >> c;
        bit.update(a, b, c);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
