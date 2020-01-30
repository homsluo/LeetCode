//
// Created by homsl on 2019/9/25.
//
int nthUglyNumber(int n) {
    if(n < 1)
        return 0;
    if(n == 1)
        return 1;
    vector<int> dp(n, 0);
    dp[0] = 1;
    int index2 = 0, index3 = 0, index5 = 0;
    for(int i = 1; i < n; i++){
        dp[i] = min(min(dp[index2]*2, dp[index3]*3),dp[index5]*5);
        if(dp[index2]*2 == dp[i]) index2++;
        if(dp[index3]*3 == dp[i]) index3++;
        if(dp[index5]*5 == dp[i]) index5++;
    }
    return dp[n-1];
}
