#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    while(cin >> n){
        ll ans = 1, a = 1;
        while(ans < n){
            ans *= ++a;
        }
        cout << a << "\n";
    }
}