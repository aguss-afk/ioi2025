#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct dsu {
    vector<int> arr, size;
    int n;
    void start(int N){
        n = N;
        arr.assign(n, 0);
        size.assign(n, 1);
        iota(all(arr), 0);
    }
    int find(int a){
        return arr[a] = (arr[a] == a ? a : find(arr[a]));
    }
    void unite(int a, int b){
        int a1 = find(a);
        int b1 = find(b);
        if(a1 == b1){
            return;
        }
        if(size[a1] > size[b1]){
            swap(a1, b1);
        }
        size[b1] += size[a1];
        arr[a1] = b1;
    }
};
dsu f, g;
bool check(int a, int b, dsu &x){
    return x.find(a) == x.find(b);
}
void solve(){
    int n, m1, m2, ans = 0;
    cin >> n >> m1 >> m2;
    f.start(n);
    g.start(n);
    vector<pair<int, int>> a, z;
    for(int i = 0; i < m1; i++){
        int c, b;
        cin >> c >> b;
        c--;
        b--;
        a.push_back({c, b});
    }    
    for(int j = 0; j < m2; j++){
        int c, b;
        cin >> c >> b;
        c--;
        b--;
        g.unite(c, b);
        z.push_back({c, b});
    }
    for(int i = 0; i < m1; i++){
        if(check(a[i].first, a[i].second, g)){
            f.unite(a[i].first, a[i].second);
            continue;
        }
        ans++;
    }
    for(int i = 0; i < m2; i++){
        if(!check(z[i].first, z[i].second, f)){
            f.unite(z[i].first, z[i].second);
            ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
