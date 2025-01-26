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
    if(n % 2){
        if(n < 27){
            cout << -1 << endl;
            return;
        }
        vector<int> arr(n, 0);
        arr[0] = 1;
        arr[9] = 1;
        arr[10] = 2;
        arr[25] = 1;
        arr[26] = 2;
        for(int i = 1; i < 9; i++){
            arr[i] = (i + 5) / 2;
        }
        for(int i = 11; i < 25; i++){
            arr[i] = (i + 3) / 2;
        }
        for(int i = 27; i < n; i++){
            arr[i] = (i + 3) / 2;
        }
        f1(i, arr){
            cout << i << sp;
        }
        cout << endl;
        return;
    } 
    for(int i = 1; i <= n / 2; i++){
        cout << i << sp << i << sp;
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
