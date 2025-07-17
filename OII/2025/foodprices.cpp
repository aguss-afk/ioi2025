#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(x) cerr << #x << ": "; for(auto &i : x) cerr << i << ' '; cerr << '\n';
#define raya(); cout << "================================" << "\n";
using namespace std;
vector<vector<int>> tree;
vector<int> arr, depth, tin, tout, father, sz;
vector<pair<long long, long long>> lim;
int timer = 0;
long long ans = 1;
const long long MOD = 1000000007;

long long binpow(long long a, long long b){
    a %= MOD;
    long long res = 1;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

long long inv(long long a){
    return binpow(a, MOD - 2);
}

int finder(int a){
    return arr[a] = (arr[a] == a ? a : finder(arr[a]));
}

void unite(int a, int b){
    a = finder(a);
    b = finder(b);
    if(a == b) return;
    if(max(lim[a].first, lim[b].first) > min(lim[a].second, lim[b].second)){
        ans = 0;
        return;
    }
    if(sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    arr[a] = b;
    long long la = lim[a].second - lim[a].first + 1;
    long long lb = lim[b].second - lim[b].first + 1;
    lim[b].first = max(lim[a].first, lim[b].first);
    lim[b].second = min(lim[a].second, lim[b].second);
    ans = ans * inv(la) % MOD * inv(lb) % MOD * (lim[b].second - lim[b].first + 1) % MOD;
}

bool can(int a, int b){
    if(a == b){
        return 1;
    }
    a = finder(a);
    b = finder(b);
    if(lim[a].first <= lim[b].second and lim[b].first <= lim[a].second){
        return true;
    }
    return false;
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

int next_step(int l, int r){
    if(is_ancestor(l, r)){
        for(const auto x : tree[l]){
            if(depth[x] > depth[l] and is_ancestor(x, r)){
                return x;
            }
        }
    } 
    return father[l];
}

bool dfs(int start, int end, int start2, int end2){
    while(true){
        if(!can(start, start2)) return 0;
        unite(start, start2);
        if(start == end) return 1;
        start = next_step(start, end);
        start2 = next_step(start2, end2);
    }
}
void dfs(int a, int b){
    tin[a] = timer++;
    for(const int &x : tree[a]){
        if(x == b) continue;
        father[x] = a;
        depth[x] = depth[a] + 1;
        dfs(x, a);
    }
    tout[a] = timer++;
}
void solve(){
    int n; 
    cin >> n;
    tree.assign(n, vector<int>(0));
    arr.assign(n, 0);
    father.assign(n, 0);
    sz.assign(n, 1);
    tin.assign(n, 0);
    tout.assign(n, 0);
    lim.assign(n, pair<int, int>());
    depth.assign(n, 0);
    iota(arr.begin(), arr.end(), 0);
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        a--;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    dfs(0, 0);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ans = ans * (b - a + 1) % MOD;
        lim[i] = {a, b};
    }
    int q;
    cin >> q;
    for(int j = 0; j < q; j++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--, r1--, l2--, r2--;
        if(ans and dfs(l1, r1, l2, r2)){
            cout << ans << '\n';
            continue;
        } 
        cout << 0 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}