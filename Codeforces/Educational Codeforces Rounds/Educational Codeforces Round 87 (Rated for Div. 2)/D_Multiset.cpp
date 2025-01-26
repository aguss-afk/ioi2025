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
    fenwick_tree(int size = 1e6 + 1) : n(size) {
        bit.assign(n, 0);
    }
    void update(int a, int b){
        while(a <= n){
            bit[a] += b;
            a += a & (-a);
        }
    }
    int add(int a){
        int res = 0;
        while(a > 0){
            res += bit[a];
            a -= a & (-a);
        }  
        return res;
    }
    int binary_search(int a){
        int l = 1, r = 1e6;
        int ans = 0;
        while(l <= r){
            int m = (r + l) / 2;
            if(add(m) >= a){
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
void solve(){
    int n, q;
    cin >> n >> q;     
    fenwick_tree bit;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        bit.update(a, 1);
    }
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        if(a < 0){
            bit.update(bit.binary_search(-a), -1);
            continue;
        }
        bit.update(a, 1);
    }
    cout << bit.binary_search(1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
