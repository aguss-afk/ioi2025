#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;
const int INF = 1e9;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    sort(arr.rbegin(), arr.rend());
    swap(arr[1], arr[n - 1]);
    int x = INF, y = 0, ans = 0;
    for(int i = 0; i < n; i++){
        x = min(x, arr[i]);
        y = max(y, arr[i]);
        ans += y - x;
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
