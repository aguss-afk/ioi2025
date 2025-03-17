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
    vector<int> cnt(n + 1), mx(n + 1, 0);
    map<int, int> ma;
    f2(i, n, 0){
        int aux;
        cin >> aux;
        if(aux <= n){
            ma[aux]++;
        }
    } 
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            mx[j] += ma[i]; 
        }
    }
    cout << *max_element(all(mx)) << endl;
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
