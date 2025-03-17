#include <bits/stdc++.h>
using namespace std;
int n, chain_n, act_pos;
vector<int> head, ind, subsize, depth, father, pos, arr, val;
vector<vector<int>> adj;
struct segment_tree {
    vector<int> st;
    int size;
    segment_tree(vector<int> &arr){
        size = 1;
        while(size < arr.size()) size *= 2;
        st.assign(size * 2, 0);
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
        st[x] = max(st[2 * x + 2], st[2 * x + 1]);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or rx <= l) return 0;
        if(lx >= l and rx <= r) return st[x];
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r){
        return query(l, r, 0, 0, size);
    }
};
int dfs(int curr, int prev = -1){
    int count = 0;
    for(int node : adj[curr]){
        if(node != prev){
            count += dfs(node);
        }
    }
    father[curr] = prev;
    if(prev != -1) depth[curr] = depth[prev] + 1;
    subsize[curr] += count;
    return subsize[curr];
}

void hld(int curr, int prev = -1){
    if(head[chain_n] == -1){
        head[chain_n] = curr;
    }
    pos[curr] = act_pos++;
    arr[pos[curr]] = val[curr];
    ind[curr] = chain_n;
    int heavy_child = -1, max_s = 0;
    for(int node : adj[curr]){
        if(node != prev and subsize[node] > max_s){
            heavy_child = node;
            max_s = subsize[node];
        }
    }
    if(heavy_child != -1){
        hld(heavy_child, curr);
    }
    for(int node : adj[curr]){
        if(node != prev and node != heavy_child){
            chain_n++;
            hld(node, curr);
        }
    }
}
int chain_head(int node){
    return head[ind[node]];
}
int path(int x, int y, segment_tree &st){
    if(depth[chain_head(x)] > depth[chain_head(y)]) swap(x, y);
    int res = 0;
    while(chain_head(x) != chain_head(y)){
        if(depth[chain_head(x)] > depth[chain_head(y)]) swap(x, y);
        res = max(res, st.query(pos[chain_head(y)], pos[y]));
        y = father[chain_head(y)];
    }
    if(depth[chain_head(x)] > depth[chain_head(y)]) swap(x, y);
    res = max(res, st.query(pos[chain_head(x)], pos[y]));
    return res;
}
int main(){
    chain_n = 0, act_pos = 0;
    head.assign(n, -1);
    ind.assign(n, -1);
    subsize.assign(n, 1);
    depth.assign(n, 0);
    adj.assign(n, vector<int>(n, 0));
    arr.assign(n, 0);
    pos.assign(n, 0);
    val.assign(n, 0);
    dfs(0);
    hld(0);
    segment_tree st(arr);
    path(0, n, st);
}