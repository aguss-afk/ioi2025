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
    int n, m;
    cin >> n >> m;
    map<int, ll> an;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        an[a] += b;
    }
    vector<int> ans;
    f1(i, an){
        ans.push_back(i.second);
    }
    sort(rall(ans));
    ll sum = 0;
    for(int i = 0; i < min((int)ans.size(), n); i++){
        sum += ans[i];
    }
    cout << sum << endl;
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
