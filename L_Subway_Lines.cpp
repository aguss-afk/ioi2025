#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

vector<vector<int>> arr;
vector<int> subsize, head, ind, depth, val, arr, pos;
struct segment_tree{
    vector<bitset<100001>> st;
    int size;
    segment_tree(vector<int>&arr){
        size = 1;
        while(size < arr.size()) size *= 2;
        st.assign(size * 2, bitset<100001>(0));
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
    bitset<100001> get_nodes(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return bitset<100001>(0);
        if(lx >= l and rx <= r) return st[x];
        int m = (lx + rx) / 2;
        auto get_nodes1 = get_nodes(l, r, 2 * x + 1, lx, m);
        auto get_nodes2 = get_nodes(l, r, 2 * x + 2, m, rx);
        return get_nodes1 | get_nodes2;
    }
    bitset<100001> get_nodes(int l, int r){
        return get_nodes(l, r, 0, 0, size);
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    subsize.assign(n, 0);
    depth.assign(n, 0);
    pos.assign(n, 0);
    head.assign(n, -1);
    ind.assign(n, 0);
    arr.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
