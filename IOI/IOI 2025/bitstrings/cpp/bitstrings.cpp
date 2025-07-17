#include <bits/stdc++.h>
#include "bitstrings.h"
using namespace std;

int count_duplicated(string S) {
  	int ans = 0;
	unordered_set<string> nse;
  	for(int i = 0; i < (int)S.size(); i += 1){
		for(int j = i + 2; j <= (int)S.size(); j += 1){
			if(j % 2 != i % 2){
				continue;
			}
			int sz = (j - i) / 2;
			string y = S.substr(i, sz);
			if(y == S.substr(i + sz, sz) and !nse.count(y)){
				nse.insert(y);
			}
		}
  	}
	for(const string x : nse){
		cout << x << "\n";
	}
  	return nse.size();
}

string find_weakest() {
  	return string(100, '0');
}

string find_strongest() {
  	return string(100, '0');
}
