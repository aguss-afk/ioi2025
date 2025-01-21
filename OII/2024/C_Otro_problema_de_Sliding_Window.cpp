#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<int> arr;
vector<ll> prefsum;
ll query(int a, int b){
    int r = a, l = b - 1;
    int i = 1;
    while(1){
        int x = r + a + i;
        
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    arr.assign(n + 1, 0);
    prefsum.assign(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i + 1];
        prefsum[i + 1] += arr[i + 1] + prefsum[i];
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << query(a, b)
    } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
