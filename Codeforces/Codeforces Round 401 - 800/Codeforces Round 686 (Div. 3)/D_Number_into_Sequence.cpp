#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
/*
GAY EL QUE LO LEA
bro? 🤨
*/
ll N = 1e5;
vector<ll> primes;
vector<bool> ip(N + 1, true);
void prime(){
    ip[0] = 0;
    ip[1] = 0;
    for(ll i = 2; i <= N; i++)
        if(ip[i] and i * i <= N)
            for(ll j = i * i; j <= N; j += i)
                ip[j] = 0;
    for(int i = 2; i <= N; i++){
        if(ip[i]) primes.push_back(i);
    }
} 

void solve(){
    ll n;
    pair<ll, ll> maxi;
    cin >> n;
    vector<ll> arr;
    map<ll, ll> ma;
    f1(i, primes){   
        if(!(n % i)){ 
            while(!(n % i)){
                n /= i;
                arr.push_back(i);
                ma[i]++;
                if(ma[i] > maxi.first)
                    maxi = {ma[i], i};
            }
        }
        if(i * i > n) break;
    }
    if(n != 1){
        arr.push_back(n);
        ma[n]++;
        if(ma[n] > maxi.first)
            maxi = {ma[n], n};
    }

    vector<ll> ans;
    for(int i = 0; i < maxi.first - 1; i++)
        ans.push_back(maxi.second);
    ll mult = maxi.second;
    f1(i, arr)
        if(i != maxi.second) mult *= i;
    ans.push_back(mult);
    cout << ans.size() << endl;
    f1(i, ans) cout << i << sp;
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    prime();
    int t;
    cin >> t;
    while(t--)
        solve();
}