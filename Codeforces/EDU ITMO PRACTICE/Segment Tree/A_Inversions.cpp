#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
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
    void set(int i, int x, int l, int r){
        if(l + 1 == r){
            st[x] = 1;
            return;
        }  
        int m = (l + r) / 2;
        if(i < m){
            set(i, 2 * x + 1, l, m);
        } else {
            set(i , 2 * x + 2, m, r);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void set(int i){
        set(i, 0, 0, size);
    }
    int sum(int l, int r, int x, int lx, int rx){
        if(rx <= l or lx >= r){
            return 0;
        }
        if(l <= lx and rx <= r){
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
    vector<int> arr(n), ans;
    segment_tree st(n + 1);
    for(int &i : arr){
        cin >> i;
        ans.push_back(st.sum(i - 1, n));
        st.set(i - 1);
    }
    for(int &i : ans){
        cout << i << ' ';
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
