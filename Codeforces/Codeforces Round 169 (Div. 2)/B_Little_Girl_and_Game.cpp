#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

void solve(){
    string y;
    cin >> y;
    int n = y.size();
    map<char, int> abc;
    f1(i, y){
        abc[i]++;
    }
    int x = 0;
    while(69420){
        int odd = 0;
        bool t = 1;
        pair<int, char> y {0, 'a'}, e {0, 'b'};
        f1(i, abc){
            if(i.second & 1){
                odd++;
                if(i.second > y.first){
                    y = {i.second, i.first};
                }
                continue;
            } 
            if(i.second > e.first){
                e = {i.second, i.first};
            }
        }
        if(odd == n){
            if(n & 1){
                if(x & 1){
                    cout << "Second";
                    return;
                }
                cout << "First";
                return;
            } 
            if(x & 1){
                cout << "First";
                return;
            }
            cout << "Second";
            return;
        }
        if(odd < 2){
            if(x & 1){
                cout << "Second";
                return;
            }
            cout << "First";
            return;
        }
        if(odd != abc.size()){
            if(!(--abc[e.second])){
                abc.erase(e.second);
            }
        } else {
            if(!(--abc[y.second])){
                abc.erase(e.second);
            }
        }
        n--;
        x++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
