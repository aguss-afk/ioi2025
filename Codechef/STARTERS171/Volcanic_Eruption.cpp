#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<int> arr, ans, volc;
vector<pair<int, int>> pos;
int n, p;

int run(int &l, int &r, int p, int lev){
    while(arr[l] != 0 and l >= 0){
        if(arr[l] <= p * lev){
            if(ans[l] > lev){
                ans[l] = lev;
            } else {
                l = -1;
                break;
            }
            l--;
            continue;
        } 
        break;
    }
    while(arr[r] != 0 and r < n){
        if(arr[r] <= p * lev){
            if(ans[r] > lev){
                ans[r] = lev;
            } else {
                r = -1;
                break;
            }
            r++;
            continue;
        }
        break;
    }
    if(l >= 0 and arr[l] != 0){
        if(r < n and arr[r] != 0){
            return min(arr[r], arr[l]);
        }
        return arr[l];
    } else if(r < n and arr[r] != 0){
        return arr[r];
    }
    return -1;
}

void solve(){
    cin >> n >> p;
    arr.assign(n, 0);
    ans.assign(n, MOD);
    int x = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(!arr[i]){
            volc.push_back(i);
            pos.push_back({i - 1, i + 1});
        }
        x = max(arr[i], x);
    }
    int lev = 1;
    while(p * (lev - 1) < x){
        int y = MOD;
        for(int i = 0; i < volc.size(); i++){
            int x = run(pos[i].first, pos[i].second, p, lev);
            if(x != -1){
                y = min(x, y);
            }
        }
        if(y != MOD){
            lev = max((y + p - 1) / p, lev + 1);
        } else {
            lev++;
        }
    }
    for(int &i : ans){
        if(i == MOD){
            cout << 0 << ' ';
            continue;
        }
        cout << i << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
