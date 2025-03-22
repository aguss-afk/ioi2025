#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(x) cerr << #x << ": "; for(const auto &i : x) cerr << i << ' '; cerr << '\n';
using namespace std;
vector<int> mi, dep, depmi;
vector<vector<int>>  arr;
struct segment_tree {
    vector<int> st;
    int size;
    segment_tree(vector<int> &arr){
        size = 1;
        while(size < arr.size()){
            size *= 2;
        }
        st.assign(size * 2, 1e6);
        build(arr, 0, 0, size);
    }
    void build(vector<int> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = min(st[2 * x + 1], st[2 * x + 2]);
    }
    int q(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return 1e6;
        if(lx + 1 == rx){
            return lx;
        }
        int m = (lx + rx) / 2;
        if(st[2 * x + 1] < st[2 * x + 2]){
            return q(l, r, 2 * x + 1, lx, m);
        }
        return q(l, r, 2 * x + 2, m, rx);
    }
    int q(int l, int r){
        return q(l, r, 0, 0, size);
    }
};

void dfs(int a, int prev = -1){
    mi.push_back(a);
    depmi.push_back(dep[a]);
    for(int &node : arr[a]){
        if(node == prev){
            continue;
        }
        dep[node] = dep[a] + 1;
        dfs(node, a);
        mi.push_back(a);
        depmi.push_back(dep[a]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    dep.assign(n, 0);
    arr.assign(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dbg(n);
    dfs(0);
    dbgv(dep);
    dbgv(mi);
    dbgv(depmi);
    segment_tree st(depmi);
    dbgv(st.st);
    while(m--){
        int a, b;
        cin >> a >> b;
        dbg(st.q(a - 1, b));
        cout << mi[st.q(a - 1, b)] << '\n';
    }
}