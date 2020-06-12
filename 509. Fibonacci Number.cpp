//
// Created by homsl on 2020/4/21.
//
int fib(int N) {
    if(N == 0)
        return 0;
    if(N == 1)
        return 1;
    return fib(N-1) + fib(N-2);
}

// Memoization

class Solution {
private:
    int memo[31] = {0};
public:
    int fib(int N) {
        if(memo[N])
            return memo[N];
        if(N == 0)
            return 0;
        if(N <= 2){
            memo[N] = 1;
            return 1;
        }
        memo[N] = fib(N-1) + fib(N-2);
        return memo[N];
    }
};
