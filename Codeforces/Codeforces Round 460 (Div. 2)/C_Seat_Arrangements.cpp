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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> arr(n, vector<char>(m));
    f1(i, arr){
        f1(j, i){
            cin >> j;
        }
    } 
    vector<vector<int>> prefvert(n + 1, vector<int>(m + 1)), prefhor(m + 1, vector<int>(n + 1));
    f2(i, n, 0){
        f2(j, m, 0){
            if(arr[i][j] == '.'){
                prefvert[i + 1][j + 1] += 1;
            }
            prefvert[i + 1][j + 1] += prefvert[i + 1][j];
        }
    }
    f2(i, m, 0){
        f2(j, n, 0){
            if(arr[j][i] == '.'){
                prefhor[i + 1][j + 1] += 1;
            }
            prefhor[i + 1][j + 1] += prefhor[i + 1][j];
        }
    }
    ll ans = 0;
    f2(i, n + 1, 1){
        f2(j, m - k + 1, 0){
            if(prefvert[i][j + k] - prefvert[i][j] == k){
                ans++;
            }
        }
    }
    f2(i, m + 1, 1){
        f2(j, n - k + 1, 0){
            if(prefhor[i][j + k] - prefhor[i][j] == k){
                ans++;
            }
        }
    }
    if(k == 1){
        ans = 0;
        f1(i, prefvert){
            ans += i[m];
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
