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
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll pos = 0, neg = 0, ze = 0;
    f1(i, arr){
        cin >> i;
        if(i > 0){
            pos++;
        }
        if(i < 0){
            neg++;
        }
        if(!i){
            ze++;
        }
    }
    if(pos > 2 or neg > 2){
        cout << "NO" << endl;
        return;
    }
    ll zet = 3;
    vector<ll> ne;
    set<ll> che;
    f1(i, arr){
        if(i){
            ne.push_back(i);
            che.insert(i);
        } else if(zet-- > 0){
            ne.push_back(i);
            che.insert(i);
        }
    }
    int N = ne.size();
    f2(i, N - 2, 0){
        f2(j, N - 1, i + 1){
            f2(k, N, j + 1){
                if(!che.count(ne[i] + ne[j] + ne[k])){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
