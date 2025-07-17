#include <bits/stdc++.h>
#include "coins.h"
using namespace std;

vector<int> coin_flips(std::vector<int> b, int c) {
    if(c < 3){
        if(c == 0){
            if(b[0] == b[1] and b[1] == b[2]){
                return {0};
            }
            if(b[0] != b[1] and b[1] == b[2]){
                return {63};
            }
            if(b[0] != b[1] and b[1] != b[2]){
                return {2};
            }
            if(b[0] == b[1] and b[1] != b[2]){
                return {1};
            }
        }
        if(c == 1){
            if(b[0] == b[1] and b[1] == b[2]){
                return {1};
            }
            if(b[0] != b[1] and b[1] == b[2]){
                return {2};
            }
            if(b[0] != b[1] and b[1] != b[2]){
                return {63};
            }
            if(b[0] == b[1] and b[1] != b[2]){
                return {0};
            }
        }
        if(b[0] == b[1] and b[1] == b[2]){
            return {2};
        }
        if(b[0] != b[1] and b[1] == b[2]){
            return {1};
        }
        if(b[0] != b[1] and b[1] != b[2]){
            return {0};
        }
        if(b[0] == b[1] and b[1] != b[2]){
            return {63};
        }
    }
    return {63};
}

int find_coin(std::vector<int> b) {
    if(b[0] != b[1] and b[0] != b[2]){
        return 0;
    }
    if(b[0] != b[1] and b[1] != b[2]){
        return 1;
    }
    if(b[2] != b[1] and b[0] != b[2]){
        return 2;
    }
    return b[0] ? 0 : 1;
}
