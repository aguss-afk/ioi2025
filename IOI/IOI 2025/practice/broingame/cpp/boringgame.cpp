#include "boringgame.h"
#include <bits/stdc++.h>
using namespace std;
long long play_game() {
  	long long l = 1, r = 1'000'000'000'000'000'001;
  	long long ans = (l + r) / 2, base = ans;
  	bool a = ask(ans);
  	if(a){
		l = ans;
  	} else {
		r = ans;
  	} 
	bool yacambio = false;
	while(l + 1 != r){
		if(!yacambio){
			int n = 9;
			long long auxl = l, auxr = r;
			while(n--){
				long long auxans = (auxl + auxr) / 2;
				if(ask(auxans)){
					auxl = auxans;
				} else {
					auxr = auxans;
				}
			}
			if(ask(base) == a){
				l = auxl;
				r = auxr;
				continue;
			}
			yacambio = 1;
			continue;
		}
		ans = (l + r) / 2;
		if(ask(ans)){
			r = ans;
		} else {
			l = ans;
		}
	}
  	return l;
}
