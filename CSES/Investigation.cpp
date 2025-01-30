#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<vector<pair<ll, ll>>> arr;
vector<ll> dis, mi, ma, num;
vector<bool> vis;
void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    dis[0] = 0; 
    num[0] = 1;
    q.push({0, 0});
    while(!q.empty()){
        ll node = q.top().second;
        q.pop();
        if(vis[node]){
            continue;
        }
        vis[node] = 1;
        for(auto &[x, y] : arr[node]){
            if(dis[node] + y < dis[x]){
                dis[x] = dis[node] + y;
                num[x] = num[node];
                mi[x] = mi[node] + 1;
                ma[x] = ma[node] + 1;
                q.push({dis[x], x});
            } else if(dis[node] + y == dis[x]){
                num[x] += num[node];
                num[x] %= MOD;
                mi[x] = min(mi[node] + 1, mi[x]);
                ma[x] = max(ma[node] + 1, ma[x]);
            }
        }
    } 
}

void solve(){
    int n, m;
    cin >> n >> m;
    arr.assign(n, vector<pair<ll, ll>>(0));
    dis.assign(n, INF);
    mi.assign(n, 0);
    ma.assign(n, 0);
    vis.assign(n, 0);
    num.assign(n, 0);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr[a].push_back({b, c});
    }  
    dijkstra();
    cout << dis[n - 1] << ' ' << num[n - 1] % MOD << ' ' << mi[n - 1] << ' ' << ma[n - 1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
