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
    vector<vector<int>> arr(n, vector<int>(n));
    vector<int> corsiz(2 * n + 1), vis(2 * n + 1, 0), posi(2 * n + 1);
    vector<vector<int>> best(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            posi[arr[i][j]]++;
            corsiz[i + j + 2]++;
        }
    }
    for(int i = 2; i < corsiz.size(); i++){
        best[corsiz[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[arr[i][j]]) continue;
            int a = posi[arr[i][j]];
            vis[best[a][0]] = 1;
            int change = arr[i][j];
            swap(posi[arr[i][j]], posi[best[a][0]]);
            for(int k = 0; k < n; k++){
                for(int m = 0; m < n; m++){
                    if(arr[k][m] == change){
                        arr[k][m] = best[a][0];
                    } else if(best[a][0] == arr[k][m]){
                        arr[k][m] = change;
                    }
                }
            }
            best[a].erase(best[a].begin());
        }
    }
    for(vector<int> &i : arr){
        for(int &j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}