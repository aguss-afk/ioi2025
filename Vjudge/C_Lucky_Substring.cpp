#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    string x;
    cin >> x;
    int n4 = 0, n7 = 0;
    for(char &i : x){
        if(i - '0' == 4){
            n4++;
        } else if(i - '0' == 7){
            n7++;
        }
    }
    if(!n4 and !n7){
        cout << -1;
    } else if(n4 == n7){
        cout << 4;
    } else if(n4 > n7){
        cout << 4;
    } else {
        cout << 7;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
