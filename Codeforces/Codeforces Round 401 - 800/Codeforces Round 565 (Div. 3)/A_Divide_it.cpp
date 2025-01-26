#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    while(1){
        if(!(n % 2)){
            n /= 2;
            ans++;
        } else if(!(n % 3)){
            n *= 2;
            n /= 3;
            ans++;
        } else if(!(n % 5)){
            n *= 4;
            n /= 5;
            ans++;
        } else {
            if(n == 1){
                cout << ans << endl;
                return;
            }
            cout << -1 << endl;
            return;
        }
    } 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
