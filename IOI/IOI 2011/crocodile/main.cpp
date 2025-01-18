#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

vector<vector<pair<ll, ll>>> arr;
set<int> p;
vector<ll> dis;
vector<bool> vis;
void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    dis[0] = 0;
    while(!q.empty()){
        ll node = q.top().second;
        q.pop();
        if(vis[node]){
            continue;
        }
        vis[node] = 1;
        for(auto [x, y] : arr[node]){
            if(dis[node] + y < dis[x]){
                dis[x] = dis[node] + y;
                q.push({dis[x], x});
            }
        }
    }
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
    arr.assign(N, vector<pair<ll, ll>>(0));
    dis.assign(N, INF);
    vis.assign(N, 0);
    for(int i = 0; i < K; i++){
        p.insert(P[i]);
    }
    for(int i = 0; i < M; i++){
		arr[R[i][0]].push_back({R[i][1], L[i]});
		arr[R[i][1]].push_back({R[i][0], L[i]});
    }
    dijkstra();
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(p.count(i)){
            ans = max(dis[i], ans);
        }
    }
    return ans;
}

void solve(){
    int n, m, k, ans;
    cin >> n >> m >> k;    
    int r[m][2], l[m], p[k];
    for(int i = 0; i < m; i++){
        cin >> r[i][0] >> r[i][1] >> l[i];
    }
    for(int i = 0; i < k; i++){
        cin >> p[i];
    }
    cin >> ans;
    if(ans == travel_plan(n, m, r, l, k, p)){
        cout << "Correct";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}