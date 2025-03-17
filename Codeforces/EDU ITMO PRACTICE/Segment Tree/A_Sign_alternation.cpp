#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct segment_tree{
    vector<pair<int, int>> st;
    int size;
    segment_tree(int n, vector<int>&arr){
        size = 1;
        while(size < n + 1) size *= 2;
        st.assign(size * 2, {0, 0});
        build(arr, 0, 0, size);
    }
    pair<int, int> merge(pair<int, int> a, pair<int, int> b){
        return {a.first + b.first, a.second + b.second};
    }
    void build(vector<int> &arr, int x, int l, int r){
        if(l + 1 == r){
            if(l < arr.size()){
                if(l & 1){
                    st[x] = {0, arr[l]};
                } else {
                    st[x] = {arr[l], 0};
                }
            }
            return;
        }
        int m = (l + r) / 2;
        build(arr, 2 * x + 1, l, m);
        build(arr, 2 * x + 2, m, r);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    void set(int i, int v, int x, int l, int r){
        if(l + 1 == r){
            if(l & 1){
                st[x] = {0, v};
            } else {
                st[x] = {v, 0};
            }
            return;
        }
        int m = (l + r) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, l, m);
        } else {
            set(i, v, 2 * x + 2, m, r);
        }
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    pair<int, int> sum(int l, int r, int x, int lx, int rx){
        if(rx <= l or lx >= r){
            return {0, 0};
        }
        if(lx >= l and rx <= r){
            return st[x];
        }
        int m = (lx + rx) / 2;
        pair<int, int> n1 = sum(l, r, 2 * x + 1, lx, m);
        pair<int, int> n2 = sum(l, r, 2 * x + 2, m, rx);
        return merge(n1, n2);
    }
    pair<int, int> sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
    void print(){
        for(int i = 0; i < 2 * size; i++){
            cout << st[i].first << ' ' << st[i].second << '\n';
        }
    }
};
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    segment_tree st(n, arr);
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a){
            pair<int, int> x = st.sum(--b, c);
            if(b & 1){
                cout << x.second - x.first << '\n';
            } else {
                cout << x.first - x.second << '\n';
            }
            continue;
        }
        st.set(--b, c);
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
