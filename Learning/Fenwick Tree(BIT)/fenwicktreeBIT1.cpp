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
int n, q;
vector<int> ft;
int add(int a){
    int res = 0, i = a;
    while(i > 0){
        res += ft[i];
        i -= i & (-i);
    }
    return res;
}
int add(int a, int b){
    return add(b) - add(a - 1);
}
void update(int a, int b){
    int i = a;
    while(i <= n){
        ft[i] += b;
        i += i & (-i);
    }
}
void solve(){
    cin >> n >> q;
    ft.assign(n + 1, 0);
    vector<int> arr(n);
    f1(i, arr){
        cin >> i;
    }
    f2(i, n + 1, 1){
        ft[i] = arr[i - 1] + ft[i - 1];
    }
    for(int i = n - 1; i > 0; i--){
        int low = (i & (i + 1)) - 1;
        if(low >= 0){
            ft[i + 1] -= ft[low + 1];
        }
    }
    while(q--){
        int o, a, b;
        cin >> o >> a >> b;
        if(o){
            cout << add(a, b) << endl;
            continue;
        }
        update(a, b);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}