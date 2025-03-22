#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(ll &i : arr){
        cin >> i;   
    }
    sort(arr.begin(), arr.end());
    ll aux = 1, ans = 0, sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += arr[i];
        if(aux == 3){
            if(sum - arr[i] < sum - sum * m / 100) sum -= arr[i];
            else sum -= sum * m / 100;
            ans += sum;
            sum = 0;
            aux = 0;
        }
        aux++;
    }
    sum -= sum * m / 100;
    ans += sum;
    cout << ans;
}
