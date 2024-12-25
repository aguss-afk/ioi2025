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
ll maxsize, minsum;
vector<ll> arr, size;
vector<vector<ll>> tree;
vector<pair<ll, pair<ll, ll>>> weights;
void unite(ll a, ll b, ll w){
    if(size[a] > size[b])
    swap(a, b);
    arr[a] = arr[b];
    size[b] += size[a];
    minsum += w;
    maxsize = max(maxsize, size[b]);
}
ll find(ll a){
    return arr[a] = (arr[a] == a ? a : find(arr[a]));
}
void solve(){
    int n, m;
    cin >> n >> m;
    tree.assign(n + 1, vector<ll>(0));
    arr.assign(n + 1, 0);
    size.assign(n + 1, 0);
    f2(i, n + 1, 0){
        arr[i] = i;
        size[i] = 1;
    }
    f2(i, m, 0){
        int a, b, w;
        cin >> a >> b >> w;
        weights.push_back({w, {a, b}});
    }
    maxsize = 1;
    sort(all(weights));
    for(int i = 0; maxsize != n; i++){
        int x = weights[i].second.first, y = weights[i].second.second;
        int a = find(x);
        int b = find(y);
        if(a != b){
            unite(a, b, weights[i].first);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
    }
    cout << minsum << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
