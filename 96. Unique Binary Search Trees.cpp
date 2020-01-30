//
// Created by homsl on 2019/9/5.
//
int numTrees(int n) {  //Recursion, TLE
    return Rec(1,n);
}

int Rec(int start, int end){
    if(start > end)
        return 0;
    if(start == end)
        return 1;
    int sum = 0;
    for(int i = start; i <= end; i++){
        int left = Rec(start, i-1);
        int right = Rec(i+1, end);
        sum += (left == 0? 1:left)*(right == 0?1:right);
    }
    return sum;
}

//--------------------------------------------------------------------

int numTrees(int n) { // DP
    long int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++)
            dp[i] += dp[i-j-1]*dp[j];
    }
    return dp[n];
}
