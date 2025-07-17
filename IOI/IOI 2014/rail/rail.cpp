#include "rail.h"
#include <bits/stdc++.h>
using namespace std;
void findLocation(int n, int first, int location[], int stype[])
{
    stype[0] = 1;
    pair<int, int> nose = {INT_MAX, -1};
    for(int i = 1; i < n; i++){
        location[i] = getDistance(0, i);
        if(location[i] < nose.first) nose = {location[i], i};
        stype[i] = 2;
    }
    for(int i = 1; i < n; i++){
        if(nose.second == i) continue;
        if(getDistance(nose.second, i) < location[i]){
            location[i] = location[nose.second] - getDistance(nose.second, i);
            stype[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        location[i] += first;
    }
}
