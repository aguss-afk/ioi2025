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
    int n, m;
    cin >> n >> m;
    map<ll, vector<int>> ma; 
    vector<ll> arr(n);
    f2(i, n, 0){
        cin >> arr[i];
        ma[arr[i]].push_back(i + 1);
    }
    f2(i, n - 1, 0){
        if(arr[i] > m - 2){
            continue;
        }
        f2(j, n, i + 1){
            ll aux = m - arr[i] - arr[j];
            if(!ma.count(aux)){
                continue;
            }
            if(aux != arr[i] and aux != arr[j]){
                cout << i + 1 << sp << j + 1 << sp << ma[aux][0];
                return;
            }
            if(ma[aux].size() > 1){
                f1(k, ma[aux]){
                    if(k != i + 1 and k != j + 1){
                        cout << k << sp << i + 1 << sp << j + 1;
                        return;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
