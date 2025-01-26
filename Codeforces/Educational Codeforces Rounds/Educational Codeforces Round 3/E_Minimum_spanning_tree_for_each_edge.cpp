#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
int LOGN;
ll maxsize, minsum;
vector<ll> arr, sizes, depth, vis;
vector<vector<ll>> up, maxw;
vector<vector<pair<ll, ll>>> tree;
vector<pair<ll, pair<ll, ll>>> weights, edges;
void dfs(ll a){
    f1(i, tree[a]){
        if(vis[i.first]){
            continue;
        }
        vis[i.first]= 1;
        up[i.first][0] = a;
        maxw[i.first][0] = i.second;
        depth[i.first] = depth[a] + 1;
        for(int j = 1; j < LOGN; j++){
            up[i.first][j] = up[up[i.first][j - 1]][j - 1];
            maxw[i.first][j] = max(maxw[i.first][j - 1], maxw[up[i.first][j - 1]][j - 1]);
        }
        dfs(i.first);
    }
}
void unite(ll a, ll b, ll w){
    if(sizes[a] > sizes[b])
    swap(a, b);
    arr[a] = b;
    sizes[b] += sizes[a];
    minsum += w;
    maxsize = max(maxsize, sizes[b]);
}
ll find(ll a){
    return arr[a] = (arr[a] == a ? a : find(arr[a]));
}

ll gethevedge(ll a, ll b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    ll k = depth[a] - depth[b], maxedge = 0;
    for(int j = LOGN - 1; j >= 0; j--){
        if(k & (1 << j)){
            maxedge = max(maxedge, maxw[a][j]);
            a = up[a][j];
        }
    }
    if(a == b){
        return maxedge;
    }
    for(int j = LOGN - 1; j >= 0; j--){
        if(up[a][j] != up[b][j]){
            maxedge = max(maxedge, maxw[a][j]);
            maxedge = max(maxedge, maxw[b][j]);
            a = up[a][j];
            b = up[b][j];
        }
    }
    maxedge = max(maxedge, max(maxw[a][0], maxw[b][0]));
    return maxedge;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    LOGN = 18;
    up.assign(n + 1, vector<ll>(LOGN));
    maxw.assign(n + 1, vector<ll>(LOGN));
    tree.assign(n + 1, vector<pair<ll, ll>>(0));
    arr.assign(n + 1, 0);
    sizes.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    f2(i, n + 1, 0){
        arr[i] = i;
        sizes[i] = 1;
    }
    f2(i, m, 0){
        ll a, b, w;
        cin >> a >> b >> w;
        weights.push_back({w, {a, b}});
        edges.push_back({w, {a, b}});
    }
    maxsize = 1;
    sort(all(weights));
    for(int i = 0; i < weights.size() and maxsize != n; i++){
        ll x = weights[i].second.first, y = weights[i].second.second;
        ll a = find(x);
        ll b = find(y);
        if(a != b){
            unite(a, b, weights[i].first);
            tree[x].push_back({y, weights[i].first});
            tree[y].push_back({x, weights[i].first});
        }
    }
    vis[1] = 1;
    dfs(1);
    f1(i, edges){
        ll hevedge = gethevedge(i.second.first, i.second.second);
        ll ans = minsum - hevedge + i.first;
        cout << ans << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
