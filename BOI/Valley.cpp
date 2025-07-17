#include <bits/stdc++.h>

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';
#define INFINITY 1e8
using namespace std;
using ll = long long;
int n, s, q, e;
int lg = 5;
vector<vector<pair<int, int>>> arr;
vector<vector<int>> up, min_shop;
vector<int> dp, depth, distances;
unordered_set<int> shops;

int lca(int a, int b);

int calc_distance(int a, int b){
    return distances[a] + distances[b] - 2 * distances[lca(a, b)];
}

void dfs_min_shop(int curr, int prev, int weight){
    min_shop[curr][0] = min(dp[curr], dp[prev] + weight);
    for(int i = 1; i <= lg; i++){
        min_shop[curr][i] = min({
            min_shop[up[curr][i - 1]][i - 1] + calc_distance(curr, up[curr][i - 1]),
            min_shop[curr][i - 1]
        });
    }
    for(auto &x : arr[curr]){
        if(x.first != prev) dfs_min_shop(x.first, curr, x.second);
    }
}

void dfs_prin(int curr, int prev = -1, int weight = 0){
    if(shops.count(curr)){
        dp[curr] = 0;
    }
    up[curr][0] = prev;
    distances[curr] = distances[prev] + weight;
    for(int i = 1; i <= lg; i++){
        up[curr][i] = up[up[curr][i - 1]][i - 1];
    }
    for(auto &i : arr[curr]){
        if(i.first == prev) continue;
        depth[i.first] = depth[curr] + 1;
        dfs_prin(i.first, curr, i.second);
        dp[curr] = min(dp[curr], dp[i.first] + i.second);
    }
}
int lca(int a, int b){
    if(depth[a] > depth[b]){
        swap(a, b);
    }
    int dif = depth[b] - depth[a];
    for(int i = lg; i >= 0; i--){
        if(dif & 1 << i){
            b = up[b][i];
        }
    }
    if(a == b){ 
        return a;
    }
    for(int i = lg; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
void solve(){
    cin >> n >> s >> q >> e; 
    e--;
    vector<pair<int, int>> roads;
    arr.assign(n, vector<pair<int, int>>());
    dp.assign(n, INFINITY);
    up.assign(n, vector<int>(lg + 1));
    depth.assign(n, 0);
    distances.assign(n, 0);
    min_shop.assign(n, vector<int>(lg + 1));
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
        roads.push_back({a, b});
    }   
    for(int i = 0; i < s; i++){
        int aux;
        cin >> aux;
        aux--;
        shops.insert(aux);
    }
    dfs_prin(e, e, 0);
    dfs_min_shop(e, e, 0);
    while(q--){
        int p, r;
        cin >> p >> r;
        p--;
        r--;
        int father;
        if(depth[roads[p].first] > depth[roads[p].second]){
            father = roads[p].first;
        } else {
            father = roads[p].second;
        }
        if(lca(father, r) != father){
            cout << "escaped\n";
        } else {
            int ans = INFINITY;
            int dis = depth[r] - depth[father];
            int longti=0;
            for(int i = 0; i <= lg; i++){
                if(dis & (1 << i)){
                    ans = min(min_shop[r][i], ans);
                    r = up[r][i]; 
                }
            }
            if(ans >= INFINITY){
                cout << "oo\n";
                continue;
            }
            cout << ans << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}