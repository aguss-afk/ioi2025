#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n - 2), ans(n, 0);
    for(int i = 0; i < n - 2; i++){
        cin >> arr[i];
    }    
    int aux = 0;
    bool t = false;
    for(int i = 1; i < n - 1; i++){
        if(arr[i - 1]){
            if(t){
                ans[i] = aux;
                continue;
            }
            if(ans[i - 1]){
                cout << "NO\n";
                return;
            }
            t = 1;
            aux++;
            ans[i - 1] = aux;
            ans[i] = aux;
            continue;
        }
        if(t){
            t = 0;
            ans[i] = aux;
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
