#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct node {
    int m, c;
};
struct segment_tree {
    vector<node> st;
    int size;
    segment_tree(int n, vector<int>&arr){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, {INT_MAX, 0});
        build(arr, 0, 0, size);
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = make_node(arr[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = merge_nodes(st[2 * x + 1], st[2 * x + 2]);
    }
    node make_node(int a){
        return {a, 1};
    }
    node merge_nodes(node a, node b){
        if(a.m < b.m){
            return a;
        }
        if(b.m < a.m){
            return b;
        }
        return {a.m, a.c + b.c}; 
    }
    void set(int i, int v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = make_node(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        st[x] = merge_nodes(st[2 * x + 1], st[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    node mincount(int x, int l, int r, int lx, int rx){
        if(rx <= l or lx >= r){
            return {INT_MAX, 0};
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (rx + lx) / 2;
        node n1 = mincount(2 * x + 1, l, r, lx, m);
        node n2 = mincount(2 * x + 2, l, r, m, rx);
        return merge_nodes(n1, n2);
    }
    node mincount(int l, int r){
        return mincount(0, l, r, 0, size);
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    segment_tree st(n, arr);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            st.set(b, c);
            continue;
        }
        node ans = st.mincount(b, c);
        cout << ans.m << ' ' << ans.c << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
