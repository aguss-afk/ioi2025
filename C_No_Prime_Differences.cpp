#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;
vector<bool> primes(1010, 1);
void is_prime(){
    primes[0] = primes[1] = 0;
    for(int i = 2; i < 1010; i++){
        if(primes[i] and i * i < 1010){
            for(int j = i * i; j < 1010; j += i){
                primes[j] = 0;
            }
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    if(primes[n] and primes[m]){
        return;
    } 
    if(primes[n]){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << (j + 1) + m * i << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (i + 1) + n * j << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    is_prime();
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
