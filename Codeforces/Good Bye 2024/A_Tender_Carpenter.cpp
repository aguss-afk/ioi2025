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

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    f1(i, arr){
        cin >> i;
    }
    bool t = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] * 2 > arr[i + 1] and arr[i + 1] * 2 > arr[i]){
            t = 1;
            break; 
        }
    }
    if(t){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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