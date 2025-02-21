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
    multiset<int> a;
    f2(i, n, 0){
        int aux;
        cin >> aux;
        a.insert(aux);
    }
    while(a.size() > 1){
        auto x = a.begin();
        int n1 = *x;
        x++;
        int n2 = *x;
        a.erase(x);
        a.erase(a.begin());
        a.insert((n1 + n2) / 2);
    }
    cout << *a.begin() << endl;
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
