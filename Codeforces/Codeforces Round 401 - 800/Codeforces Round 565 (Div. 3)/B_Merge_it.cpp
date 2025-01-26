#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> ma;
    f1(i, arr){
        cin >> i;
        ma[i % 3]++;
    }
    int ans = ma[0], x = ma[1], y = ma[2], z = min(x, y);
    ans += z;
    x -= z;
    y -= z;
    ans += x / 3;
    ans += y / 3;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--)
        solve();
}