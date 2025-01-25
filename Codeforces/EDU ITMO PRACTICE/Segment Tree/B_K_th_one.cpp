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
        st[x] = st[2 * x + 1] + st[2 * x + 2];
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
    void change(int i, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] ^= 1;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            change(i, 2 * x + 1, lx, m);
        } else {
            change(i, 2 * x + 2, m, rx);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void change(int i){
        change(i, 0, 0, size);
    }
    int get_kth(int k, int x, int lx, int rx){
        if(lx + 1 == rx){
            return lx;
        }
        int m = (lx + rx) / 2;
        ll ans = st[2 * x + 1];
        if(ans > k){
            ans = get_kth(k, 2 * x + 1, lx, m);
        } else {
            ans = get_kth(k - ans, 2 * x + 2, m, rx);
        }
        return ans;
    }
    int get_kth(int k){
        return get_kth(k, 0, 0, size);
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
        int a, k;
        cin >> a >> k;
        if(a == 1){
            st.change(k);
            continue;
        }
        cout << st.get_kth(k) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
