#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << "\n";
using namespace std;
string x;
int ans = 0;
char faceup(int a){
    ans++;
    return x[a - 1];
}

void play() {
	map<char, vector<int>> nose;
	vector<bool> ac(25, 0);
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXY";
	int ya = 0;
	for(int i = 1; i <= 50; i += 2){
		char a = faceup(i);
		char b = faceup(i + 1);
        nose[a].push_back(i);
		nose[b].push_back(i + 1);
		if(a == b){
			int x = a - 'A';
			ac[x] = 1;
		}
		ya++;
	}
	for(int i = 1; i <= 25; i++){
		if(!ac[i - 1]){
			faceup(nose[abc[i - 1]][0]);
			faceup(nose[abc[i - 1]][1]);
		}
	}
}

int main(){
    cin >> x;
    play();
    cout << ans;
}
