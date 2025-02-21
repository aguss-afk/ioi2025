#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> count;
    for(int &i : arr){
        cin >> i;
        count[i]++;
    }
    bool t = 0;
    pair<int, int> ans, c;
    c = {-1, -1};
    ans = {-1, -1};
    for(int i = 0; i < n; i++){
        if(count[arr[i]] > 1){
            if(t){
                if(ans.second - ans.first > c.second - c.first){
                    c = {ans.first, ans.second};
                }
            }
            t = 0;
            continue;
        }
        if(t){
            ans.second++;
            continue;
        }
        t = 1;
        ans = {i, i};
    }
    if(c.first == -1){
        if(ans.first == -1){
            cout << 0 << '\n';
            return;
        }
        c = ans;
    }
    if(ans.second - ans.first > c.second - c.first){
        c = ans;
    }
    cout << c.first + 1 << ' ' << c.second + 1 << '\n';
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
