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
        st.assign(2 * size, 0);
    }
    void set(int i, int x, int l, int r){
        if(l + 1 == r){
            st[x] ^= 1;
            return;
        }
        int m = (l + r) / 2;
        if(i < m){
            set(i, 2 * x + 1, l, m);
        } else {
            set(i, 2 * x + 2, m, r);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void set(int i){
        set(i, 0, 0, size);
    }
    int sum(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l){
            return 0;
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for(int &i : arr){
        cin >> i;
    }
    segment_tree st(2 * n);
    vector<int> vis(n, -1), ans(n);
    for(int i = 0; i < 2 * n; i++){
        if(vis[arr[i] - 1] != -1){
            ans[arr[i] - 1] = st.sum(vis[arr[i] - 1] + 1, i);
            st.set(vis[arr[i] - 1]);
            continue;
        }
        vis[arr[i] - 1] = i;
        st.set(i);
    }
    reverse(arr.begin(), arr.end());
    vis.assign(n, -1);
    for(int i = 0; i < 2 * n; i++){
        if(vis[arr[i] - 1] != -1){
            ans[arr[i] - 1] += st.sum(vis[arr[i] - 1] + 1, i);
            st.set(vis[arr[i] - 1]);
            continue;
        }
        vis[arr[i] - 1] = i;
        st.set(i);
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
