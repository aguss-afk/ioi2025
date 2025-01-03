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
    vector<char> arr(n);
    vector<ll> prefp(n + 1, 0), prefh(n + 1, 0), prefs(n + 1, 0);
    f2(i, n, 0){
        cin >>  arr[i];
        if(arr[i] == 'P'){
            prefp[i + 1]++;
        } else if(arr[i] == 'S'){
            prefs[i + 1]++;
        } else {
            prefh[i + 1]++;
        }
        prefp[i + 1] += prefp[i];
        prefs[i + 1] += prefs[i];
        prefh[i + 1] += prefh[i];
    }
    ll sum = 0;
    f2(i, n + 1, 0){
        sum = max(sum, prefp[i] + prefs[n] - prefs[i]);
        sum = max(sum, prefp[i] + prefh[n] - prefh[i]);
        sum = max(sum, prefs[i] + prefp[n] - prefp[i]);
        sum = max(sum, prefs[i] + prefh[n] - prefh[i]);
        sum = max(sum, prefh[i] + prefp[n] - prefp[i]);
        sum = max(sum, prefh[i] + prefs[n] - prefs[i]);
    }
    cout << sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    solve();
}
