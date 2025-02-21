#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct node {
    int el;
    int con;
};
struct segment_tree {
    vector<node> st;
    int size;
    segment_tree(vector<int>& arr){
        size = 1;
        int n = arr.size();
        while(size < n){
            size *= 2;
        }
        st.assign(2 * size, {0, 0});
        build(arr, 0, 0, size);
    }
    void build(vector<int>& arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = {arr[lx], 1};
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        node a = st[2 * x + 1];
        node b = st[2 * x + 2];
        st[x] = {a.el + b.el, a.con + b.con};
    }
    int erasenget(int i, int x, int lx, int rx){
        if(lx + 1 == rx){
            int ans = st[x].el;
            st[x] = {0, 0};
            return ans;
        }
        int m = (lx + rx) / 2;
        int ans;
        if(st[2 * x + 1].con >= i){
            ans = erasenget(i, 2 * x + 1, lx, m);
        } else {
            ans = erasenget(i - st[2 * x + 1].con, 2 * x + 2, m, rx);
        }
        node a = st[2 * x + 1];
        node b = st[2 * x + 2];
        st[x] = {a.el + b.el, a.con + b.con};
        return ans;
    }
    int erasenget(int i){
        return erasenget(i, 0, 0, size);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    segment_tree st(arr);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        cout << st.erasenget(aux) << ' ';
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
