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
    int n, ans = 0;
    cin >> n;
    vector<string> pin(n);
    f1(i, pin)
        cin >> i;
    //f1(i, pin){
    //    cout << i << endl;
    //}
    f2(i, n - 1, 0){
        f2(j, n, i + 1){
            if(pin[j] == pin[i]){
                vector<bool> rep(10, 0);
                f2(k, n, 0){
                    rep[pin[k][0] - '0'] = 1;
                }
                f2(k, 10, 0){
                    if(!rep[k]){
                        pin[i][0] = k + '0';
                    }
                }
                ans++;
                break;
            }
        } 
    }
    cout << ans << endl;
    f1(i, pin){
        cout << i << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}
