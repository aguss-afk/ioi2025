#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), first(n / 2), second(n / 2);
    map<int, int> a;
    for(int &i : arr){
        cin >> i;
        a[i]++;
    }
    for(auto &[x, y] : a){
        if(y < 2){
            cout << "No\n";
            return;
        }
        first.push_back(x);
        second.push_back(x);
        y -= 2;
        if(y){
            a[x + 1] += y;
        }
    }
    cout << "Yes\n";
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
