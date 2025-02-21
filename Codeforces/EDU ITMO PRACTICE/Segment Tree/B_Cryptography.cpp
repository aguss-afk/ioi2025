#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
ll MOD;
struct matrix {
    ll a, b, c, d;
};
struct segment_tree{
    vector<matrix> st;
    ll size;
    matrix NEUTRAL = {1, 0, 0, 1};
    segment_tree(ll n, vector<matrix>& arr){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, NEUTRAL);
        build(0, 0, size, arr);
    }
    matrix merge(matrix a, matrix b){
        return {
            (a.a * b.a + a.b * b.c) % MOD, 
            (a.a * b.b + a.b * b.d) % MOD, 
            (a.c * b.a + a.d * b.c) % MOD, 
            (a.c * b.b + a.d * b.d) % MOD
        };
    }
    void build(ll x, ll l, ll r, vector<matrix> &arr){
        if(l + 1 == r){
            if(l < arr.size()){
                st[x] = arr[l];
            }
            return;
        } 
        ll m = (l + r) / 2;
        build(2 * x + 1, l, m, arr);
        build(2 * x + 2, m, r, arr);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    matrix getans(ll l, ll r, ll x, ll lx, ll rx){
        if(lx >= r or rx <= l){
            return NEUTRAL;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        ll m = (lx + rx) / 2;
        matrix n1 = getans(l, r, 2 * x + 1, lx, m);
        matrix n2 = getans(l, r, 2 * x + 2, m, rx);
        return merge(n1, n2);
    }
    matrix getans(ll l, ll r){
        return getans(l, r, 0, 0, size);
    }
};
void solve(){
    ll n, q;
    cin >> MOD >> n >> q;
    vector<matrix> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
    }
    segment_tree st(n + 1, arr);
    while(q--){
        ll a, b;
        cin >> a >> b;
        a--;
        matrix ans = st.getans(a, b);
        cout << ans.a << ' ' << ans.b << '\n' << ans.c << ' ' << ans.d << "\n\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        ll t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
