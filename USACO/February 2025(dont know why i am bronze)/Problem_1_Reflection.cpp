#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
int n;
vector<vector<char>> arr;
vector<char> func(int a, int b){
    return {arr[a][b], arr[a][n - 1 - b], arr[n - 1 - a][b], arr[n - 1 - a][n - 1 - b]};
}
void solve(){
    int m;
    cin >> n >> m;
    arr.assign(n, vector<char>(n));
    for(vector<char> &i : arr){
        for(char &j : i){
            cin >> j;
        }
    }
    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < n / 2; j++){
            vector<char> aux = func(i, j);
            int n1 = 0, n2 = 0;
            for(char &k : aux){
                if(k == '.'){
                    n1++;
                    continue;
                }
                n2++;
            }
            ans += min(n1, n2);
        }
    }
    cout << ans << '\n';
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        vector<char> aux = func(a, b);
        int n1 = 0, n2 = 0;
        for(char &k : aux){
            if(k == '.'){
                n1++;
                continue;
            }
            n2++;
        }
        ans -= min(n1, n2);
        arr[a][b] = arr[a][b] == '.' ? '#' : '.';
        aux = func(a, b);
        n1 = 0, n2 = 0;
        for(char &k : aux){
            if(k == '.'){
                n1++;
                continue;
            }
            n2++;
        }
        ans += min(n1, n2);
        cout << ans << '\n';
    }
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
