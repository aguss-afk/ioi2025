#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct fenwick_tree {
    vector<int> bit;
    int n;
    fenwick_tree(int n) : n(n){
        bit.assign(n + 1, 0);
    }
    int getsum(int a){
        int res = 0;
        while(a > 0){
            res += bit[a];
            a -= a & (-a);
        }
        return res;
    }
    void update(int a, int b){
        while(a <= n){
            bit[a] += b;
            a += a & (-a);
        }
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    fenwick_tree bit(1e6 + 1);
    map<int, int> id;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        bit.update(a, 1);
        bit.update(b + 1, -1);
        id[a] = i;
    }
    unordered_set<int> ans;
    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        for(int j = 0; j < c; j++){
            int a;
            cin >> a;
            int b = bit.getsum(a);
            map<int, int>::iterator it = id.upper_bound(a);
            for(int i = 0; i < b; i++){
                ans.insert(it-- -> second);
            }
        }
        cout << ans.size() << "\n";
        ans.clear();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
