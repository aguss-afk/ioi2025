#include"holiday.h"

long long int findMaxAttraction(int n, int start, int d, int attraction[]) {
    int dp[n + 1][n + 1][d + 1] = {0};
    for(int i = 1; i <= n; i++){
        dp[i][i][1] = attraction[i - 1];
    } 
    for(int i = 1; i <= n; j++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= d; k++){

            }
        }
    }
    return dp[n][n][d];
}
