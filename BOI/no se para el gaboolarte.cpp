#include <bits/stdc++.h>
int lca(int a,int b){
    if(prof[a]>prof[b]){
        swap(a,b);
    }
    int dif=prof[b]-prof[a];
    for(int i=20;i>=0;i--){
        if(dif&(1<<i)){
            b=padre[b][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=20;i>=0;i--){
        if(padre[a][i]!=padre[b][i]){
            b=padre[b][i];
            a=padre[a][i];
        }
    }
    return padre[a][0];
}