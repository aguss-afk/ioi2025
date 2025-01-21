#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

struct segment_tree {
    vector<int> st;
    int size;
    void build(vector<int> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < (int)arr.size()){
                st[x] = arr[lx];
            }
            return;
        }
        int m = (rx + lx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = min(st[2 * x + 1], st[2 * x + 2]);
    }
    segment_tree(int n, vector<int>&arr){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, INT_MAX);
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(lx == rx - 1){
            st[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        st[x] = min(st[2 * x + 1], st[2 * x + 2]); 
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    int minrange(int x, int l, int r, int lx, int rx){
        if(lx >= r or rx <= l){
            return INT_MAX;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (lx + rx) / 2;
        int n1 = minrange(2 * x + 1, l, r, lx, m);
        int n2 = minrange(2 * x + 2, l, r, m, rx);
        return min(n1, n2);
    }
    int minrange(int l, int r){
        return minrange(0, l, r, 0, size);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    }
    segment_tree st(n, arr);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            st.set(b, c);
            continue;
        }
        cout << st.minrange(b, c) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
