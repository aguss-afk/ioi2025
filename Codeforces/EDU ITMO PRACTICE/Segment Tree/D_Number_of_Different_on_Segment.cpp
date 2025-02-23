#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

struct segment_tree {
    vector<bitset<41>> st;
    int size;
    segment_tree(vector<int> &arr){
        int n = arr.size();
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(2 * size, bitset<41>(0));
        build(arr, 0, 0, size);
    }
    void build(vector<int>&arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x][arr[lx]] = 1;
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = st[2 * x + 1] | st[2 * x + 2];
    }
    void set(int i, int v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x].reset();
            st[x][v] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        st[x] = st[2 * x + 1] | st[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    void get(int l, int r, int x, int lx, int rx, bitset<41>&ans){
        if(lx >= r or rx <= l){
            return;
        }
        if(lx >= l and rx <= r){
            ans = ans | st[x];
            return;
        }
        int m = (lx + rx) / 2;
        get(l, r, 2 * x + 1, lx, m, ans);
        get(l, r, 2 * x + 2, m, rx, ans);
    }
    int get(int l, int r){
        bitset<41> ans;
        get(l, r, 0, 0, size, ans);
        return ans.count();
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    } 
    segment_tree st(arr);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1){
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
