#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    unordered_set<int> siz;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            if(arr[i] % primes[j] == 0){
                arr[i] = primes[j];
                siz.insert(arr[i]);
                break;
            }
        }
    } 
    cout << siz.size() << '\n';
    map<int, int> pos;
    int j = 1;
    for(auto &i : siz){
        pos[i] = j++;
    }
    for(int &i : arr){
        cout << pos[i] << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
