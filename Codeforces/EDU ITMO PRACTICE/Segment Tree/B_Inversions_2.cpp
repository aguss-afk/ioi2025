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
            set(i, 2 * x + 2, m, r);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void set(int i){
        set(i, 0, 0, size);
    }
    int get(int k, int x, int l, int r){
        if(l + 1 == r){
            st[x] = 0;
            return l;
        }
        int m = (l + r) / 2;
        int ans = 0;
        if(st[2 * x + 2] >= k){
            ans = get(k, 2 * x + 2, m, r);
        } else {
            ans = get(k - st[2 * x + 2], 2 * x + 1, l, m);
        }
        st[x] = st[2 * x + 1] + st[2 * x + 2];
        return ans;
    }
    int get(int k){
        return get(k, 0, 0, size);
    }
};

void solve(){
    int n;
    cin >> n;
    segment_tree st(n);
    vector<int> arr(n), ans; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        st.set(i);
    }
    for(int i = n - 1; i >= 0; i--){
        ans.push_back(st.get(arr[i] + 1) + 1);
    }
    reverse(ans.begin(), ans.end());
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
