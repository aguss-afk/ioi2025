#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(x) cerr << #x << ": "; for(const auto &i : x) cerr << i << ' '; cerr << '\n';
using namespace std;
using ll = int;

vector<ll> subsize, arr, pos, head, ind, dep, fat;
vector<vector<int>> adj;
int chn, ap;
struct segment_tree {
    vector<ll> st;
    int size;
    segment_tree(vector<ll> &arr){
        size = 1;
        while(size < arr.size()){
            size *= 2;
        }
        st.assign(size * 2, 0);
        build(arr, 0, 0, size);
    }
    void build(vector<ll> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void update(int i, int v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) update(i, v, 2 * x + 1, lx, m);
        else update(i, v, 2 * x + 2, m, rx);
        st[x] = st[2 * x + 1] + st[2 * x + 2];
    }
    void update(int i, int v){
        update(i, v, 0, 0, size);
    }
    ll q(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return 0;
        if(lx >= l and rx <= r) return st[x];
        int m = (lx + rx) / 2;
        return q(l, r, 2 * x + 1, lx, m) + q(l, r, 2 * x + 2, m, rx);
    }
    ll q(int l, int r){
        return q(l, r, 0, 0, size);
    }
};
int ch(int a){
    return head[ind[a]];
}

int dfs(int curr, int prev = -1){
    subsize[curr] = 1;
    for(int &node : adj[curr]){
        if(node == prev) continue;
        dep[node] = dep[curr] + 1;
        fat[node] = curr;
        subsize[curr] += dfs(node, curr);
    }
    return subsize[curr];
}

void hld(int curr, int prev = -1){
    if(head[chn] == -1){
        head[chn] = curr;
    }
    pos[curr] = ap++;
    ind[curr] = chn;
    int hc = -1, ms = -1;
    for(int &no : adj[curr]){
        if(subsize[no] > ms and no != prev){
            ms = subsize[no];
            hc = no;
        }
    }
    if(hc != -1){
        hld(hc, curr);
    }
    for(int &no : adj[curr]){
        if(no != prev and no != hc){
            chn++;
            hld(no, curr);
        }
    }
}

int query(int x, int y, segment_tree &st){
    ll res = 0;
    while(ch(x) != ch(y)){
        if(dep[ch(x)] > dep[ch(y)]) swap(x, y);
        res += st.q(pos[ch(y)], pos[y] + 1);
        y = fat[ch(y)];
    }
    if(dep[x] > dep[y]) swap(x, y);
    res += st.q(pos[x] + 1, pos[y] + 1);
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    subsize.assign(n, 0);
    pos.assign(n, 0);
    adj.assign(n, vector<int>());
    head.assign(n, -1);
    ind.assign(n, 0);
    arr.assign(n, 1);
    dep.assign(n, 0);
    fat.assign(n, 0);
    chn = 0, ap = 0;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    hld(0);
    segment_tree st(arr);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(a, b, st) << '\n';
    }
}