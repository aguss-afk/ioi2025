#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    vector<int> arr(1000001, 0);
    vector<int> coins(a);
    for(int &i : coins){
        cin >> i;
    }
    sort(coins.begin(), coins.end());
    arr[0] = 1;
    for(int i = 0; i <= b; i++){
        for(int &j : coins){
            if(j > b or j > i){
                break;
            }
            if(arr[i - j]){
                arr[i] += arr[i - j];
            }
        }
    }
    for(int i = 0; i <= b; i++){
        cout << arr[i] << ' ';
    }
    cout << arr[b];
}