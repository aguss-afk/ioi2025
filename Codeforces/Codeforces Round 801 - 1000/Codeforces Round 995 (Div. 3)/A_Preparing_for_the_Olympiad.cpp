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
    vector<int> a1(n), a2(n);
    f1(i, a1){
        cin >> i;
    } 
    f1(i, a2){
        cin >> i;
    }
    int x = 0;
    int y = 0;
    f2(i, n - 1, 0){
        if(a2[i + 1] < a1[i]){
            y += a2[i + 1];
            x += a1[i];
        }
    }
    x += a1[n - 1];
    cout << (x - y) << endl;
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
