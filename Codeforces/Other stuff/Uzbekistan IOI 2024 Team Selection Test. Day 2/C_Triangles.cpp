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

vector<ll> arr;
ll x(ll a, ll b){
    vector<ll> c;
    for(int i = a; i <= b; i++){
        c.push_back(arr[i]);
    }
    sort(all(c));
    for(int i = c.size() - 1; i > 1; i--){
        for(int j = i - 1; j > 0; j--){
            for(int k = j - 1; k >= 0; k--){
                if(c[i] + c[j] > c[k] and c[j] + c[k] > c[i] and c[i] + c[k] > c[j]){
                    return c[i] + c[j] + c[k];
                }
            }
        }
    }
    return 0;
}
void solve(){
    int n, q;
    cin >> n >> q;   
    arr.assign(n, 0);
    f1(i, arr){
        cin >> i;
    }
    while(q--){
        bool a;
        ll b, c;
        cin >> a >> b >> c;
        if(a){
            cout << x(b, c) << endl;
        } else {
            arr[b] = c;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
