#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << "\n";

using namespace std;
typedef long long ll;

vector<ll> calculate_costs(vector<int> w, vector<int> a, vector<int> b, vector<int> e) {
	int n = w.size();
	ll sumb = accumulate(b.begin(), b.end(), 0);
    dbg(sumb);
	if(n % 2){
		ll minans = 1e17;
		for(int i = 0; i < n; i++){
			minans = min(minans, sumb - b[i] + a[i]);
		}
		vector<ll> ans(e.size(), minans);
		return ans;
	}
	return vector<ll>(e.size(), sumb);
}

int main(){
    int n;
    cin >> n;
    vector<int> w(n), a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> a[i] >> b[i];
    }
    int q;
    cin >> q;
    vector<int> e(q);
    for(int i = 0; i < q; i++){
        cin >> e[i];
    }
    vector<long long> ans = calculate_costs(w, a, b, e);
    for(long long &i : ans){
        cout << i << ' ';
    }
}