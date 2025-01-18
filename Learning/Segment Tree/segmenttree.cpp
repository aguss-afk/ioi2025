#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

struct segtree {
    vector<ll> st;
    int size;
    segtree(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(2 * size, 0);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            st[x] = v;
            return;
        }
        int m = (rx + lx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    ll sum(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx){
            return 0;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (rx + lx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }
    ll sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    segtree st(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.set(i, x);
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            st.set(b, c);
            continue;
        }
        cout << st.sum(b, c) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}