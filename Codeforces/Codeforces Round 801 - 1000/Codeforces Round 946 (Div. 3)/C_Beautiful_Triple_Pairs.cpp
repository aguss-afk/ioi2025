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
    vector<int> arr(n);
    vector<map<pair<int, int>, map<int, int>>> ma(3);
    vector<map<pair<int, int>, int>> sum(3);
    f1(i, arr){
        cin >> i;
    }
    f2(i, n - 2, 0){
        ma[0][{arr[i], arr[i + 1]}][arr[i + 2]]++;
        sum[0][{arr[i], arr[i + 1]}]++;
        ma[1][{arr[i], arr[i + 2]}][arr[i + 1]]++;
        sum[1][{arr[i], arr[i + 2]}]++;
        ma[2][{arr[i + 1], arr[i + 2]}][arr[i]]++;
        sum[2][{arr[i + 1], arr[i + 2]}]++;
    }
    ll ans = 0;
    f2(i, 3, 0){
        f1(j, ma[i]){
            ll aux = 0;
            f1(k, j.second){
                aux += k.second * (sum[i][j.first] - k.second);
            }
            aux /= 2;
            ans += aux;
        }
    }
    cout << ans << endl;
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
