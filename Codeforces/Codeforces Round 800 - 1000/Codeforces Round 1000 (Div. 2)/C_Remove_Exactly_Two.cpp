#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    multiset<int> m;
    for(int i = 0; i < n; i++){
        m.insert(arr[i].size());
        for(int &j : arr[i]){
            ans = max(ans, (int)arr[i].size() + (int)arr[j].size() - 2);
        }
    }
    for(int i = 0; i < n; i++){
        m.erase(m.find(arr[i].size()));
        for(int &j : arr[i]){
            m.erase(m.find(arr[j].size()));
        }
        if(!m.empty()){
            ans = max(ans, (int)arr[i].size() + *m.rbegin() - 1);
        }
        m.insert(arr[i].size());
        for(int &j : arr[i]){
            m.insert(arr[j].size());
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
