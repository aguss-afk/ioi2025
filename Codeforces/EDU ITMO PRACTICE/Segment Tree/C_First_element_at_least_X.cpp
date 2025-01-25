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
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = max(st[2 * x + 1], st[2 * x + 2]);
    }
    segment_tree(vector<int> &arr){
        int n = (int)arr.size();
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(size * 2, 0);
        build(arr, 0, 0, size);
    }
    void set(int i, int v, int x, int l, int r){
        if(l + 1 == r){
            st[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, l, m);
        } else {
            set(i, v, 2 * x + 2, m, r);
        }
        st[x] = max(st[2 * x + 1], st[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    int find_x(int v, int x, int l, int r){
        if(st[x] < v){
            return -1;
        }
        if(l + 1 == r){
            return l;
        }
        int m = (l + r) / 2;
        int res = find_x(v, 2 * x + 1, l, m);
        if(res == -1){
            res = find_x(v, 2 * x + 2, m, r);
        }
        return res;
    }
    int find_x(int k){
        return find_x(k, 0, 0, size);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    segment_tree st(arr);
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int b, c;
            cin >> b >> c;
            st.set(b, c);
            continue;
        } 
        int b;
        cin >> b;
        cout << st.find_x(b) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
