#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    if(a % b == 0){
        cout << b << ' ' << 1;
    }
}