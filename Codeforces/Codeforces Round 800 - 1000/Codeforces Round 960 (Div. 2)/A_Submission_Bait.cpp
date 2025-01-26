#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> ma;
    f1(i, arr){
        cin >> i;
        ma[i]++;
    }
    vector<int> ac;
    int ans = 0;
    f1(i, ma) ac.push_back(i.second);
    f1(i, ac){
        ans += i;
        if(ans & 1) {
            cout << "yEs" << endl;
            return;
        }
    }
    cout << "nO" << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--)
        solve();
}