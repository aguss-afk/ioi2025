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
    int n, m, j;
    cin >> n >> m;
    vector<int> arr(n), ans(n, MOD);
    bool x = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i and x){
            if(arr[i] + arr[i - 1] > m){
                j = i;
                x = 0;
            }
        }
    }
    for(int i = j; i < n; i++){
        j--;
        if(j > 0){
            while(arr[i] + arr[j] > m){
                j--;
                if(j < 0){
                    break;
                }
            }
        }
        ans[i] = j;
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if((b - a + 1) & 1){
            b--;
        } 
        if(a > ans[b]){
            cout << 0;
            continue;
        }
        cout << 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
