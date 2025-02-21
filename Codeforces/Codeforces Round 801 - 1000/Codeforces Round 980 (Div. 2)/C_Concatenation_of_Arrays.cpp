#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr, ts;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
        ts.push_back({a + b, min(a, b), i});
    }
    sort(ts.begin(), ts.end());
    for(auto x : ts){
        cout << arr[x[2]][0] << ' ' << arr[x[2]][1] << ' ';
    }
    cout << '\n';
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
