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
/*
    Stupid horseshit I am
    Couldn't solve it without help :(
    Maybe I will come back to solve it once I have improved 
*/
ll n, k;
ll x;
bool check(){
    x = 0;
    for(int i = 0; i < n; i++)
        x += abs(n - 2 * i - 1);
    dbg(x);
    if(k > x or k % 2) return 0;
    return 1;
}
void solve(){
    cin >> n >> k;    
    if(!check()){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<ll> arr(n);
    f2(i, n + 1, 1) arr[i - 1] = i;
    f1(i, arr) cout << i << sp;
    cout << endl;
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
