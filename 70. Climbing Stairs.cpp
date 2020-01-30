//
// Created by homsl on 2019/8/30.
//
int climbStairs(int n) {
    vector<int> memo(n+1,0);
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2; i <= n; i++)
        memo[i] = memo[i-1]+memo[i-2];
    return memo[n];
}

int climbStairs(int n) {
    long int a = 1, b = 1;
    while(n--)
        a = (b += a) - a;
    return a;
}
