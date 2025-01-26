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
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    ll sum1 = 0, sum2 = 0;
    vector<int> vec1, vec2;
    for(int i = 0; i <= b; i++){
        vec1.push_back(arr[i]);
    }
    for(int i = a; i < n; i++){
        vec2.push_back(arr[i]);
    }
    sort(all(vec1));
    sort(all(vec2));
    for(int i = 0; i < b - a + 1; i++){
        sum1 += vec1[i];
        sum2 += vec2[i];
    }
    cout << min(sum1, sum2) << '\n';
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
