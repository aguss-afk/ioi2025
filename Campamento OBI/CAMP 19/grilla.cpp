#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    bool t = 0;
    if((x + y) & 1){
        t = 1;
    }
    while(n--){
        long long a, b;
        char c;
        cin >> a >> b >> c;
        if((a + b) & 1 == 1){
            if(t == 1){
                if(c == 'B'){
                    cout << "SI\n";
                    continue;
                }
                cout << "NO\n";
                continue;
            }
            if(c == 'B'){
                cout << "NO\n";
                continue;
            }
            cout << "SI\n";
            continue;
        }
        if(t == 1){
            if(c == 'B'){
                cout << "NO\n";
                continue;
            }
            cout << "SI\n";
            continue;
        }
        if(c == 'B'){
            cout << "SI\n";
            continue;
        }
        cout << "NO\n";
    }
}