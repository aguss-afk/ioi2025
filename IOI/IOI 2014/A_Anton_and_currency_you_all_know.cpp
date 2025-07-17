#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    string x;
    cin >> x;
    int n = (int)x.size();
    bool sepuede = false;
    int pos = -1;
    for(int i = n - 1; i >= 0; i--){
        if((x[i] - '0') % 2){
            continue;
        }
        sepuede = true;
        if(pos == -1){
            pos = i;
            continue;
        }
        if(x[i] < x[n - 1]){
            pos = i;
        }
    }
    swap(x[n - 1], x[pos]);
    cout << (sepuede ? x : "-1");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
