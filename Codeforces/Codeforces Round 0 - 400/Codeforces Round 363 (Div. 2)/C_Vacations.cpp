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
    f1(i, arr){
        cin >> i;
    } 
    vector<vector<int>> d(n + 1, vector<int>(3, 0)); 
    f2(i, n + 1, 1){
        int ma = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
        d[i][0] = ma;
        if(arr[i - 1] == 1 or arr[i - 1] == 3){
            d[i][1] = max(d[i - 1][0] + 1, d[i - 1][2] + 1);
        }
        if(arr[i - 1] == 2 or arr[i - 1] == 3){
            d[i][2] = max(d[i - 1][0] + 1, d[i - 1][1] + 1);
        }
    }
    int ans = max(d[n][0], max(d[n][1], d[n][2]));
    cout << n - ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
