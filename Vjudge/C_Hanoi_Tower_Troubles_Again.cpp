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
    vector<int> arr(n, 0);
    for(int i = 1; ; i++){
        bool t = 0;
        for(int j = 0; j < n; j++){
            float x1 = sqrt(i + arr[j]);
            if(floor(x1) == ceil(x1) or !arr[j]){
                arr[j] = i;
                t = 1;
                break;
            }
        }
        if(!t){
            cout << i - 1 << endl;
            return;
        }
    }
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
