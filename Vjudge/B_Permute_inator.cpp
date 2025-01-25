#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<vector<int>> check(127, vector<int>(127, -1));
    int c = 0, k;
    for(int i = 0; i < n; i++){
        c = 0;
        for(int j = 0; j < n; j++){
            if(check[i][j] != -1){
                c += check[i][j];
                continue;
            }
            if(i == j){
                check[i][j] = 0;
                continue;
            }
            cout << "? 2 " << i << ' ' << j << endl;
            cout.flush();
            cin >> k;
            check[i][j] = k;
            check[j][i] = k ^ 1;
            c += k;
        }
        ans[i] = c;
    }
    cout << "! ";
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout.flush();
    return;
}
int main(){
    solve();
    return 0;
}
