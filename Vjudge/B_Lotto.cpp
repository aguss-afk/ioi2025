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
int k, N;
vector<int> arr, comb;
vector<vector<int>> ans;
void for1(int s, int d){
    if(d == 6){
        ans.push_back(comb);
    }
    for(int i = s; i < k; i++){
        comb.push_back(arr[i]);
        for1(i + 1, d + 1);
        comb.pop_back();
    }
}
void solve(int K, vector<int> ar, int n){
    ans.clear();
    comb.clear();
    k = K;
    arr = ar;
    for1(0, 0);
    f2(i, ans.size(), 0){
        f1(j, ans[i]){
            cout << j << sp;
        }
        if(i != ans.size() - 1 or n != N - 1){
            cout << endl; 
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int, vector<int>>> cases;
    while(1){
        int K;
        cin >> K;
        if(K == 0){
            break;
        }
        vector<int> ar(K);
        f1(i, ar){
            cin >> i;
        }
        cases.push_back({K, ar});
    }
    N = cases.size();
    f2(i, N, 0){
        solve(cases[i].first, cases[i].second, i);
        if(i != N - 1){
            cout << endl;
        }
    }
    cout << endl;
}
