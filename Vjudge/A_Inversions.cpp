#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

struct segment_tree {
    vector<int> st;
    int size;
    segment_tree(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, 0);
    } 
    void build(int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = 0;
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);
    }
    void update(int i, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x]++;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            update(i, 2 * x + 1, lx, m);
        } else {
            update(i, 2 * x + 2, m, rx);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void update(int i){
        update(i, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l){
            return 0;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (lx + rx) / 2;
        int n1 = query(l, r, 2 * x + 1, lx, m);
        int n2 = query(l, r, 2 * x + 2, m, rx);
        return n1 + n2;
    }
    int query(int l, int r){
        return query(l, r, 0, 0, size);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), ans(n, 0);
    segment_tree st(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans[i] = st.query(arr[i], n + 1);
        st.update(arr[i]);
    }
    for(int &i : ans){
        cout << i << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
