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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    } 
    for(int i = 0; i < n - 1; i++){
        if(arr[i] <= arr[i + 1]){
            arr[i + 1] -= arr[i];
            arr[i] = 0;
        }
    }
    if(is_sorted(all(arr))){
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
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
