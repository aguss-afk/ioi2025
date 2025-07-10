#include <bits/stdc++.h>
#include "insects.h"
#define dbg(x) cerr << #x << ": " << x << "\n";
using namespace std;
int min_cardinality(int N) {
	unordered_set<int> hey;
	vector<int> lista, lista2;
	for(int i = 0; i < N; i++){
		move_inside(i);
		hey.insert(i);
		lista.push_back(i);
	}	
	int ma = press_button();
	while(true){
		if(ma == (int)lista.size()) break;
		lista.clear();
		lista2.clear();
		for(const int &i : hey){
			move_outside(i);
			if(press_button() == ma){
				lista.push_back(i);
				continue;
			}
			ma--;
			lista2.push_back(i);
		}
		for(const int &i : lista2){
			hey.erase(i);
			move_outside(i);
		}
		for(const int &i : lista){
			move_inside(i);
		}
		ma = press_button();
	}	
	return ma;
}
