#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
vector<int> arr;
void pripro(){
    ll sum = 0;
    for(int i = 0; sum <= 1e9; i++){
        sum += 2 + 3 * i;
        arr.push_back(sum);
    }
}
void solve(){
    int n, ans = 0;
    cin >> n;
    while(n != 0 and n != 1){
        n -= *prev(upper_bound(all(arr), n));
        ans++;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pripro();
    int t;
    cin >> t;
    cout << endl;
    while(t--){
        solve();
    }
}
