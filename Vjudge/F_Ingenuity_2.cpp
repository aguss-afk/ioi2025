#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string str;
    int x = 0, y = 0;
    cin >> str;
    map<char, char> ma;
    ma['N'] = 'S';
    ma['S'] = 'N';
    ma['E'] = 'W';
    ma['W'] = 'E';
    for(char &i : str){
        if(i == 'N') y++;
        else if(i == 'S') y--;
        else if(i == 'E') x++;
        else x--;
    }
    if(x % 2 or y % 2){
        cout << "NO\n";
        return;
    }
    string res = "";
    for(int i = 0; i < n; i++){
        res.push_back('R');
    }
    if(!x and !y){
        if(n == 2){
            cout << "NO\n";
            return;
        }
        res[0] = 'H';
        for(int i = 0; i < n; i++){
            if(str[i] == ma[str[0]]){
                res[i] = 'H';
                break;
            }
        }
        cout << res << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == 'N' and y > 0) {
            y -= 2;
            res[i] = 'H';
        }
        if (str[i] == 'S' and y < 0) {
            y += 2;
            res[i] = 'H';
        }
        if (str[i] == 'E' and x > 0) {
            x -= 2;
            res[i] = 'H';
        }
        if (str[i] == 'W' and x < 0) {
            x += 2;
            res[i] = 'H';
        }
    } 
    cout << res << '\n';
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
