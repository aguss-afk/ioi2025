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
vector<bool> ip(100000, 1);
vector<int> p;
void solve(){
    ll n;
    cin >> n; 
    vector<ll> arr;
    int s = sqrt(n);
    for(int i = 0; i <= s; i++){
        arr.push_back(i);
    }
    for(int i = 1; i <= s; i++){
        arr.push_back(n / i);
    }
    set<ll> ans;
    f1(i, arr){
        ans.insert(i);
    }
    cout << ans.size() << endl;
    f1(i, ans){
        cout << i << sp;
    }
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
