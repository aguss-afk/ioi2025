#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(x) cerr << #x << ": "; for(auto i : x) cerr << i << ' '; cerr << "\n";
vector<int> subsize, pos, father, depth, head, ind;
vector<ll> arr, val;
int chain_n, act_pos;
int chain_head(int a){
    return head[ind[a]];
}
struct segment_tree {
    vector<ll> st;
    int size;
    segment_tree(vector<ll>&arr){
        size = 1;
        while(size < arr.size()){
            size *= 2;
        }
        st.assign(size * 2, -1);
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
        st[x] = max(st[2 * x + 1], st[2 * x + 2]);
    }
    ll maxq(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return 0;
        if(lx >= l and rx <= r) return st[x];
        int m = (lx + rx) / 2;
        ll n1 = maxq(l, r, 2 * x + 1, lx, m);
        ll n2 = maxq(l, r, 2 * x + 2, m, rx);
        return max(n1, n2);
    }
    ll maxq(int l, int r){
        return maxq(l, r, 0, 0, size);
    }
    void update(int i, ll v, int x, int lx, int rx){
        if(lx + 1 == rx){
            st[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            update(i, v, 2 * x + 1, lx, m);
        } else {
            update(i, v, 2 * x + 2, m, rx);
        }
        st[x] = max(st[2 * x + 1], st[2 * x + 2]);
    }
    void update(int i, int v){
        update(i, v, 0, 0, size);
    }
};

vector<vector<int>> adj;
int dfs(int curr, int prev = -1){
    subsize[curr] = 1;
    for(int &node : adj[curr]){
        if(node != prev){
            depth[node] = depth[curr] + 1;
            father[node] = curr;
            subsize[curr] += dfs(node, curr);
        }
    }
    return subsize[curr];
}
int query(int x, int y, segment_tree &st){
    ll res = -1;
    while(chain_head(x) != chain_head(y)){
        if(depth[chain_head(x)] > depth[chain_head(y)]) swap(x, y);
        res = max(res, st.maxq(pos[chain_head(y)], pos[y] + 1));
        y = father[chain_head(y)];
    }
    if(depth[x] > depth[y]) swap(x, y);
    res = max(res, st.maxq(pos[x], pos[y] + 1));
    return res;
}
void hld(int curr, int prev = -1){
    if(head[chain_n] == -1){
        head[chain_n] = curr;
    }
    ind[curr] = chain_n;
    pos[curr] = act_pos;
    arr[pos[curr]] = val[curr];
    act_pos++;
    int heavy_child = -1, max_s = -1;
    for(int &node : adj[curr]){
        if(subsize[node] > max_s and node != prev){
            max_s = subsize[node];
            heavy_child = node;
        }
    }
    if(heavy_child != -1){
        hld(heavy_child, curr);
    }
    for(int &node : adj[curr]){
        if(node != prev and node != heavy_child){
            chain_n++;
            hld(node, curr);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    val.assign(n, 0);
    father.assign(n, 0);
    depth.assign(n, 0);
    adj.resize(n);
    arr.assign(n, 0);
    pos.assign(n, 0);
    subsize.assign(n, 0);
    head.assign(n, -1);
    ind.assign(n, 0);
    chain_n = 0, act_pos = 0;
    for(ll &i : val){
        cin >> i;
    }
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
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            st.update(pos[--b], c);
            continue;
        }
        cout << query(--b, --c, st) << ' ';
    }
}