//
// Created by homsl on 2020/4/20.
//
int consecutiveNumbersSum(int N) {
    // n consecutive number can be as:
    // 1 + 2 + 3 + ... + n
    // the next number with n consecutive number will be:
    // 2 + 3 + 4 + ... + n + n+1 = 1 + 2 + 3 + ... + n + n
    // Thus, for every input N, calculate if(N - (1+n)*n/2) % n = 0, this is a valid answer
    int ans = 0;
    for(int n = 2; (1+n)*n/2 <= N; n++){
        if((N-(1+n)*n/2) % n == 0)
            ans++;
    }
    return ans+1;
}
