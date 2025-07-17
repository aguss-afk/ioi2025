#include <bits/stdc++.h>
#include "bitstrings.h"
using namespace std;

int count_duplicated(string S) {
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
  	return nse.size();
}

string find_weakest() {
  	string x = "10001110010111010001110110010111001011101000111011010011100101110100011101100101110010111010001110110";
	return x;
}

string find_strongest() {
	string x = "1001001100100110001010010011001001100010100100110010011000101001001100100110001010010011001001100010";
	return x;
}
