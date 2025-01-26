#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct fenwick_tree {
    vector<ll> bit;
    int n;
    fenwick_tree(int n) : n(n){
        bit.assign(n + 1, 0ll);
    }
    ll getsum(int a){
        ll res = 0;
        while(a > 0){
            res += bit[a];
            a -= a & (-a);
        }
        return res;
    }
    void update(int a, ll b){
        while(a <= n){
            bit[a] += b;
            a += a & (-a);
        }
    }
};
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    vector<vector<ll>> op(m, vector<ll>(3));
    fenwick_tree bit(n + 1);
    for(ll &i : arr){
        cin >> i;
    }
    bit.update(1, arr[0]);
    for(int i = 0; i < n - 1; i++){
        bit.update(i + 2, arr[i + 1] - arr[i]);
    }
    for(vector<ll> &x : op){
        for(ll &y : x){
            cin >> y;
        }
    }
    fenwick_tree numoq(m + 1);
    while(k--){
        int a, b;
        cin >> a >> b;
        numoq.update(a, 1);
        numoq.update(b + 1, -1);
    }
    for(int i = 0; i < m; i++){
        ll numoo = numoq.getsum(i + 1);
        if(numoo){
            bit.update(op[i][0], numoo * op[i][2]);
            bit.update(op[i][1] + 1, -(numoo * op[i][2]));
        }
    }
    for(int i = 0; i < n; i++){
        cout << bit.getsum(i + 1) << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
