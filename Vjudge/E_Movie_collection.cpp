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
int n, m;
vector<int> arr, pos;
int add(int a){
    int res = 0;
    while(a > 0){
        res += arr[a];
        a -= a & (-a);
    }
    return res;
}
void update(int a, int b){
    while(a <= n + m){
        arr[a] += b;
        a += a & (-a);
    }
}
void solve(){
    cin >> n >> m;
    int currtop = m;
    arr.assign(n + m + 1, 0);
    pos.assign(n + 1, 0);
    f2(i, n, 0){
        pos[i + 1] = i + m + 1;
        update(pos[i + 1], 1);
    }
    while(m--){
        int aux;
        cin >> aux;
        cout << add(pos[aux] - 1) << sp;
        update(pos[aux], -1);
        pos[aux] = currtop--;
        update(pos[aux], 1);
    }
    cout << endl;
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
