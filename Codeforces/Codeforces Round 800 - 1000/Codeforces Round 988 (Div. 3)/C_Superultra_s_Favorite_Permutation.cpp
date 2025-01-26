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
    vector<int> ans;
    if(n < 5){
        cout << -1 << endl;
        return;
    } else if(n < 9){
        int x = 9 - n;
        if(!(x % 2)) x = 9 - x;
        for(int i = 1; i <= n; i += 2){
            if(i != x){
                ans.push_back(i);
            }
        }
        ans.push_back(x);
        if(n % 2){
            n--;
        }
        ans.push_back(9 - x);
        for(int i = n; i > 0; i -= 2){
            if(i != 9 - x){
                ans.push_back(i);
            } 
        }
    } else {
        for(int i = 3; i <= n; i += 2){
            ans.push_back(i);
        }
        ans.push_back(1);
        if(n % 2){
            n--;
        }
        ans.push_back(8);
        for(int i = n; i > 0; i -= 2){
            if(i != 8){
                ans.push_back(i);
            }
        }
    }
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
