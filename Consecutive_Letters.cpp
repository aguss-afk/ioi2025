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
    dsu(string x){
        int n = x.size();
        arr.assign(n, 0);
        size.assign(n, 1);
        iota(all(arr), 0);
        for(int i = 0; i < n - 1; i++){
            if(x[i] == x[i + 1] and x[i] != '#'){
                unite(i, i + 1);
            }
        }
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return;
        }
        if(size[a] > size[b]){
            swap(a, b);
        }
        arr[a] = b;
        size[b] += size[a];
    }
    int find(int a){
        return arr[a] = (arr[a] == a ? a : find(arr[a]));
    }
};
void solve(){
    string x, y;
    cin >> x;
    y = x; 
    int t;
    cin >> t;
    vector<pair<int, int>> q;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == 2){
            x[b] = '#';
        }
        q.push_back({a, b});
    }
    dsu u(x);
    vector<int> ans;
    for(int i = q.size() - 1; i >= 0; i--){
        if(q[i].first == 2){
            x[q[i].second] = y[q[i].second];
            if(q[i].second and y[q[i].second] == y[q[i].second - 1]){
                u.unite(q[i].second, q[i].second - 1);
            }
            if(q[i].second != x.size() - 1 and y[q[i].second] == y[q[i].second + 1]){
                u.unite(q[i].second, q[i].second + 1);
            }
            continue;
        }
        ans.push_back(u.size[u.find(q[i].second)]);
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cout << "Case " << i + 1 << ":\n";
        solve();
    }
}

