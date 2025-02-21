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
    string x;
    cin >> x;
    ll sum = 0, n2 = 0, n3 = 0;
    f1(i, x){
        sum += i - '0';
        if(i == '2') n2++;
        else if(i == '3') n3++;
    }    
    if(sum % 9){
        bool t = true;
        ll m = 9 - sum % 9, lim = 6 * n3 + 2 * n2;
        if(m & 1){
            m += 9;
        }
        while(m <= lim){
            ll auxm = m;
            auxm -= min(n3, (auxm / 6)) * 6;
            if(auxm / 2 <= n2){
                t = 0;
                break;
            }
            m += 18;
        }
        if(t){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        return;
    }
    cout << "YES" << endl;
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