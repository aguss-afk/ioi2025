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
    for(int &i : arr){
        cin >> i;
    }
    vector<pair<int, pair<int, int>>> ans;
    for(int i = 0; i < n; i++){
        int max = 0, end = i, count = 0;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[i]){
                count++;
            } else if(arr[j] > arr[i]){
                count--;
            }
            if(count > max){
                max = count;
                end = j;
            }
        }
        ans.push_back({max, {i, end}});
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans[0].second.first + 1 << ' ' << ans[0].second.second + 1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
