#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll dif = 0;
    ll curr = n;
    string aynose = to_string(n);
    ll bef = 0, act;
    vector<int> arr;
    for(char &x : aynose){
        bef += x - '0';
    }
    for(int i = 0; i <= 6; i++){
        ans += bef;
        act = 0;
        curr = curr * 10 + n;
        for(char &a : to_string(curr)) act += a - '0';
        dif = act - bef;
        arr.push_back(dif);
    }
    for(int i : arr){
        cout << i << ' ';
    }
}