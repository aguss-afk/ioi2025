#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct segment_tree {
    vector<ll> st;
    int size;
    segment_tree(vector<ll> &arr){
        size = 1;
        while(size < arr.size()){
            size *= 2;
        }
        st.assign(size * 2, 1e9);
        build(arr, 0, 0, size);
    }
    void build(vector<ll> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = min(st[2 * x + 1], st[2 * x + 2]);
    }
    void update(int i, int v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) update(i, v, 2 * x + 1, lx, m);
        else update(i, v, 2 * x + 2, m, rx);
        st[x] = min(st[2 * x + 1], st[2 * x + 2]);
    }
    void update(int i, int v){
        update(i, v, 0, 0, size);
    }
    ll q(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return 1e9;
        if(lx >= l and rx <= r) return st[x];
        int m = (lx + rx) / 2;
        return min(q(l, r, 2 * x + 1, lx, m), q(l, r, 2 * x + 2, m, rx));
    }
    ll q(int l, int r){
        return q(l, r, 0, 0, size);
    }
};
int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll &i : arr){
        cin >> i;
    }
    segment_tree st(arr);
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            st.update(b - 1, c);
            continue;
        }
        cout << st.q(b - 1, c) << '\n';
    }
}