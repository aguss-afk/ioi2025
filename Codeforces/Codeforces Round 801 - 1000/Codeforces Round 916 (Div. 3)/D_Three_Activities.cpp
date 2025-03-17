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
    int n;
    cin >> n;
    vector<vector<pair<ll, ll>>> arr(3, vector<pair<ll, ll>>(n));
    f2(i, 3, 0){
        f2(j, n, 0){
            ll aux;
            cin >> aux;
            arr[i][j] = {aux, j};
        }
    }
    sort(rall(arr[0]));
    sort(rall(arr[1]));
    sort(rall(arr[2]));
    vector<vector<pair<ll, ll>>> idk(3, vector<pair<ll, ll>>(3));
    f2(i, 3, 0){
        f2(j, 3, 0){
            idk[i][j] = arr[i][j];
        }
    }
    ll maxsum = 0;
    f2(i, 3, 0){
        f2(j, 3, 0){
            f2(k, 3, 0){
                pair<ll, ll> a = idk[0][i];
                pair<ll, ll> b = idk[1][j];
                pair<ll, ll> c = idk[2][k];
                if(a.second != b.second and a.second != c.second and b.second != c.second){
                    maxsum = max(maxsum, a.first + b.first + c.first);
                }
            }
        }
    }
    cout << maxsum << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
