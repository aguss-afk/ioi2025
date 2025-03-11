#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    string a;
    int b;
    cin >> a >> b;
    int ans = 0;
    for(char x : a){
        ans += x - '0';
    }
    if(ans <= b){
        cout << 0 << '\n';
        return;
    }
    int count = 0, i = 0;
    while(count < b){
        count += a[i] - '0';
        i++;
    }
    int j = a.size() - 1;
    while(a[j] - '0' == 0){
        j--;
    }
    bool t = 0;
    for(int k = i - 1; k < j; k++){
        if(9 - a[k] + '0' or t){
            cout << 9 - a[k] + '0';
            t = 1;
        }
    }
    cout << (10 - a[j] + '0') * (ll)pow(10, a.size() - j - 1);
    cout << '\n';
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
