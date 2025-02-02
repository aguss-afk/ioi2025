#include"holiday.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> arr;
ll ans = 0;
vector<bool> vis;
vector<vector<ll>> dpcaca;

ll r(int d, int curr){
    if(d <= 0 or curr >= n){
        return 0;
    }
    if(dpcaca[curr][d] != -1){
        return dpcaca[curr][d];
    }
    ll n1 = arr[curr] + r(d - 2, curr + 1);
    ll n2 = r(d - 1, curr + 1);
    return dpcaca[curr][d] = max(n1, n2);
}

ll l(int d, int curr){
    if(d <= 0 or curr < 0){
        return 0;
    }
    if(dpcaca[curr][d] != -1){
        return dpcaca[curr][d];
    }
    ll n1 = arr[curr] + l(d - 2, curr - 1);
    ll n2 = r(d - 1, curr - 1);
    return dpcaca[curr][d] = max(n1, n2);
}
long long int findMaxAttraction(int N, int start, int d, int attraction[]) {
    n = N;
    arr.assign(n, 0);
    copy(attraction, attraction + n, arr.begin());
    for(int i = 0; i < n; i++){
        dpcaca.assign(n + 5, vector<ll>(d + 5, -1));
        dpcaca.clear();
        ans = max(ans, l(d - abs(start - i), i));
        dpcaca.assign(n + 5, vector<ll>(d + 5, -1));
        dpcaca.clear();
        ans = max(ans, r(d - abs(start - i), i));
    }
    return ans;
}
