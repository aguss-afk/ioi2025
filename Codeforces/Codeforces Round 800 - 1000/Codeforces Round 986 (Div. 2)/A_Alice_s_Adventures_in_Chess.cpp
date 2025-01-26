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
    int n, x, y;
    cin >> n >> x >> y;
    string str;
    cin >> str;
    int ix = 0, iy = 0;
    int j = 0;
    while(j++ < 100){
        f1(i, str){
            if(i == 'N'){
                iy++;
            } else if(i == 'S'){
                iy--;
            } else if(i == 'E'){
                ix++;
            } else {
                ix--;
            }
            if(ix == x and iy == y){
                cout << "YES" << endl;
                return;
            }
        }
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
