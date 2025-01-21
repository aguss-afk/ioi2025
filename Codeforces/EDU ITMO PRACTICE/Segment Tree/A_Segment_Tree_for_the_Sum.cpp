#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct segment_tree {
    vector<ll> st;
    int size;
    segment_tree(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, 0);
    }
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
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void build(vector<int> &arr){
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
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
    ll sum(int x, int l, int r, int lx, int rx){
        if(rx <= l or lx >= r){
            return 0;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (lx + rx) / 2;
        ll s1 = sum(2 * x + 1, l, r, lx , m);
        ll s2 = sum(2 * x + 2, l, r, m, rx);
        return s1 + s2;
    }
    ll sum(int l, int r){
        return sum(0, l, r, 0, size);
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    }
    segment_tree st(n);
    st.build(arr);
    while(q--){
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
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}