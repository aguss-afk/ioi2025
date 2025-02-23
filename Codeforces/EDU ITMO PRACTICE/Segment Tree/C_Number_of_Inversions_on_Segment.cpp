#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct inv {
    int count;
    fenwick_tree vec;
    inv(int i, int n){
        vec.update(i, n);
    }
};
struct fenwick_tree {
    vector<int> ft;
    fenwick_tree() : ft(41, 0){}
    void update(int a, int b){
        while(a <= 40){
            ft[a] += b;
            a += a & (-a);
        }
    }
    int get(int a, int b){
        int res = 0;
        while(a > 0){
            res += ft[a];
            a -= a & (-a);
        } 
        return res;
    }
};
struct segment_tree {
    vector<inv> st;
    int size;
    int compute_size(int n){
        int x = 1;
        while(x < n){
            x *= 2;
        }
        return x;
    }
    segment_tree(const vector<int>&arr) : size(compute_size(arr.size())), st(2 * size, {0, vector<int>(41, 0)}) { 
        build(arr, 0, 0, size);
    }
    void build(const vector<int> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = inv(arr[lx], 1);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = st[2 * x + 1]; 
    }
    int get(int a, int b){}
    int set(int a, int b){}
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
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(!(a - 1)){
            cout << st.get(b, c) << '\n';
            continue;
        }
        st.set(b, c);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
