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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<pair<int, int>> order;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            order.push_back({arr[i][j], i});
        }
    }
    sort(all(order));
    bool t = 1;
    for(int i = 0; i < n * m - n; i++){
        if(order[i].second != order[i + n].second){
            t = 0;
            break;
        }
    }
    if(t){
        for(int i = 0; i < n; i++){
            cout << order[i].second + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    cout << "-1\n";
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
