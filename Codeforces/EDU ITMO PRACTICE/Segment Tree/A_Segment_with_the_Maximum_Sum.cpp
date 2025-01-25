#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct item {
    ll seg, pref, suf, sum;
};

item single(int v){
    if(v > 0){
        return {v, v, v, v};
    }
    return {0, 0, 0, v};
}

item merge(item a, item b){
    return {
        max(a.seg, max(b.seg, a.suf + b.pref)),
        max(a.pref, a.sum + b.pref),
        max(b.suf, a.suf + b.sum),
        a.sum + b.sum
    };
}

struct segment_tree {
    vector<item> st;
    int size;
    const item NEUTRAL = {0, 0, 0, 0};
    void build(vector<int> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < (int)arr.size()){
                st[x] = single(arr[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    segment_tree(int n, vector<int> &arr ){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(2 * size, NEUTRAL);
        build(arr, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    ll get_sum(){
        //for(int i = 0; i < size; i++){
        //    cout << st[i].seg << ' ';
        //}
        return st[0].seg;
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
    cout << st.get_sum() << '\n';
    while(q--){
        int a, b;
        cin >> a >> b;
        st.set(a, b);
        cout << st.get_sum() << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
