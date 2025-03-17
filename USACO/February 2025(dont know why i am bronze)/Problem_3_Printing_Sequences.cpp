Santiago Soto, [2/22/2025 1:48 PM]
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vc vector<char>
#define ull unsigned long long
#define pll pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define ff(i, p, x) for(ll i = p; i < x; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ed "\n"
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
ll MOD = 1e9+7;

int main(){
 IO
 ll t;
 cin >> t;
 while(t--){
  ll n, k;
  cin >> n >> k;
  vector<pll> seq;
  vl arr(n);
  ll cur = 1;
  ff(i, 0, n){
   cin >> arr[i];
  }
  ff(i, 1, n){
   if(arr[i] != arr[i-1]){
    seq.pb({arr[i-1], cur});
    cur = 0;
   }
   cur++;
  }
  seq.pb({arr[n-1], cur});
  if(k == 1){
   if(count(all(arr), arr[0]) != n){
    cout << "NO" << ed;
   }
   else{
    cout << "YES" << ed;
   }
   continue;
  }
  if(k == 2){
   if(seq.size() <= 2){
    cout << "YES" << ed;
    continue;
   }
   if(seq.size() % 2 != 0){
    cout << "NO" << ed;
    continue;
   }
   ll sz = seq.size();
   bool univ = false;
   ff(divitions, 2, sz){
    //cout << "DIVVVVVV " << divitions << ed << ed;
    if(sz % divitions != 0){
     continue;
    }
    ll jumps = sz/divitions;
    bool ok = true;
    ff(i, 0, jumps){
     //cout << "I " << ed;
     //cout << seq[i].fi << " " << seq[i].se << "  ";
     for(ll j = i+jumps; j < sz; j+= jumps){
      //cout << seq[j].fi << " " << seq[j].se << "  ";
      if(seq[i].fi != seq[j].fi || seq[i].se != seq[j].se){
       //cout << "NO" << ed << ed;
       ok = false;
       break;
      }
     }
     if(!ok){
      break;
     }
    }
    if(ok){
     univ = true;
     break;
    }
   }
   if(univ){
    cout << "YES" << ed;
   }
   else{
    cout << "NO" << ed;
   }
  }
  else{
   vector<pll> real = seq;
   if(seq.size() <= 3){
    cout << "YES" << ed;
    continue;
   }
   bool univ = false;
   ll sz = seq.size();
   //normal
   ff(divitions, 2, sz){
    //cout << "DIVVVVVV " << divitions << ed << ed;
    if(sz % divitions != 0){
     continue;
    }
    ll jumps = sz/divitions;
    bool ok = true;
    ff(i, 0, jumps){
     //cout << "I " << ed;
     //cout << seq[i].fi << " " << seq[i].se << "  ";
     for(ll j = i+jumps; j < sz; j+= jumps){
      //cout << seq[j].fi << " " << seq[j].se << "  ";
      if(seq[i].fi != seq[j].fi || seq[i].se != seq[j].se){
       //cout << "NO" << ed << ed;
       ok = false;
       break;
      }
     }
     if(!ok){
      break;
     }
    }
    if(ok){
     univ = true;
     break;
    }
   }
   //ignore first
   seq.clear();
   ff(i, 1, real.size()){
    seq.pb({real[i].fi, real[i].se});
   }
   sz = seq.size();
   ff(divitions, 2, sz){
    //cout << "DIVVVVVV " << divitions << ed << ed;
    if(sz % divitions != 0){
     continue;
    }
    ll jumps = sz/divitions;
    bool ok = true;
    ff(i, 0, jumps){
     //cout << "I " << ed;
     //cout << seq[i].fi << " " << seq[i].se << "  ";
     for(ll j = i+jumps; j < sz; j+= jumps){
      //cout << seq[j].fi << " " << seq[j].se << "  ";
      if(seq[i].fi != seq[j].fi || seq[i].se != seq[j].se){
       //cout << "NO" << ed << ed;
       ok = false;
       break;
      }
     }
     if(!ok){
      break;
     }
    }
    if(ok){
     univ = true;
     break;
    }
   }
   //ignore last
   seq.clear();
   ff(i, 0, real.size()-1){
    seq.pb({real[i].fi, real[i].se});
   }
   sz = seq.size();
   ff(divitions, 2, sz){
    //cout << "DIVVVVVV " << divitions << ed << ed;
    if(sz % divitions != 0){
     continue;
    }
    ll jumps = sz/divitions;
    bool ok = true;
    ff(i, 0, jumps){
     //cout << "I " << ed;
     //cout << seq[i].fi << " " << seq[i].se << "  ";
     for(ll j = i+jumps; j < sz; j+= jumps){
      //cout << seq[j].fi << " " << seq[j].se << "  ";
      if(seq[i].fi != seq[j].fi || seq[i].se != seq[j].se){
       //cout << "NO" << ed << ed;
       ok = false;
       break;
      }
if(!ok){
      break;
     }
    }
    if(ok){
     univ = true;
     break;
    }
   }
   
   if(univ){
    cout << "YES" << ed;
   }
   else{
    cout << "NO" << ed;
   }
  }
  
 }
 
    return 0;
}