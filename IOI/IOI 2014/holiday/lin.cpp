#include"holiday.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ATRA;
vector<vector<ll>> dp;
ll maxi=0,N;
ll solveiz(ll dia, ll posicion){
    if(dia<=0 || posicion<0 || posicion>=N){
        return 0;
    }
    if(dp[dia][posicion]!=0){
        return dp[dia][posicion];
    }
    ll op1=ATRA[posicion]+solveiz(dia-2,posicion-1);
    ll op2=solveiz(dia-1,posicion-1);
    return dp[dia][posicion]=max(op1,op2);
}
ll solvede(ll dia, ll posicion){
    if(dia<=0 || posicion<0 || posicion>=N){
        return 0;
    }
    if(dp[dia][posicion]!=0){
        return dp[dia][posicion];
    }
    ll op1=ATRA[posicion]+solvede(dia-2,posicion+1);
    ll op2=solvede(dia-1,posicion+1);
    return dp[dia][posicion]=max(op1,op2);
}
ll findMaxAttraction(int n,int start,int d,int attraction[]) {
    N=n;
    ATRA.resize(n);
    for(ll i=0;i<n;i++){
        ATRA[i]=attraction[i];
    }
    for(ll i=0;i<n;i++){
        dp.clear();
        dp.assign(d+5,vector<ll>(n+5,0));
        maxi=max(maxi,solveiz(d-abs(start-i),i));
        dp.clear();
        dp.assign(d+5,vector<ll>(n+5,0));
        maxi=max(maxi,solvede(d-abs(start-i),i));
    }
    return maxi;
}