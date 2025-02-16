#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct segment_tree {
    vector<ll> st;
    int size;
    segment_tree(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, 0ll);
    }
    void set(int i, ll v, int x, int l, int r){
        if(l + 1 == r){
            st[x] += v;
            return;
        }
        int m = (l + r) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, l, m);
        } else {
            set(i, v, 2 * x + 2, m, r);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void set(int i, ll v){
        set(i, v, 0, 0, size);
    }
    ll sum(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l){
            return 0;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
    ll sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    segment_tree st(n + 1);
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int b, c;
            ll d;
            cin >> b >> c >> d;
            st.set(b, d);
            st.set(c, -d);
            continue;
        }
        int b;
        cin >> b;
        cout << st.sum(0, b + 1) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
