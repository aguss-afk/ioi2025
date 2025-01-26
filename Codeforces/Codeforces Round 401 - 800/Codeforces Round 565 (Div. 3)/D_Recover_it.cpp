#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
int N = 3 * 1000 * 1000 + 13;
vector<bool> primes(N + 1, 1);
map<int, int> pos;
void calcprimes(){
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= N; i += 2) {
        if (primes[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }
        if(i == 2) i--;
    }
    int x = 1;
    f2(i, N + 1, 0)
        if(primes[i])
            pos[i] = x++;
}
void solve(){
    int n;
    cin >> n;
    multiset<int> se;
    vector<int> a;
    f2(i,  2 * n, 0){
        int aux;
        cin >> aux;
       
        se.insert(aux);
    }
    while(!se.empty()){
        int mx = *se.rbegin();
        if(primes[mx]){
            int posi = pos[mx];
            se.erase(se.find(mx));
            se.erase(se.find(posi));
            a.push_back(posi);
        } else {
            int maxdiv = 1;
            for(int i = 2; i * i <= mx; i++){
                if(!(mx % i)){
                    maxdiv = i;
                    break;
                }
            }
            se.erase(se.find(mx));
            se.erase(se.find(mx / maxdiv));
            a.push_back(mx);
        }
    }
    f1(i, a){
        cout << i << sp;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calcprimes();
    solve();
}
