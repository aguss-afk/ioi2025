#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(int n){
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vector<int> arr(a - 1);
        for(int &j : arr){
            cin >> j;
        }
        int sum = 0, an = -10000000, start = 0, end = 0, tstart = 0;
        for(int j = 0; j < a - 1; j++){
            sum += arr[j];
            if(sum > an or (sum == an and (j - tstart > end - start))){
                an = sum;
                start = tstart;
                end = j;
            }
            if(sum < 0){
                sum = 0;
                tstart = j + 1;
            }
        }
        if(an > 0){
            cout << "The nicest part of route " << i + 1 << " is between stops " << start + 1 << " and " << end + 2 << '\n';
            continue;
        }
        cout << "Route " << i + 1 << " has no nice parts\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            solve(i);
        }
        return 0;
    }
    int n;
    while(cin >> n){
        solve(n);
    }
    return 0;
}
