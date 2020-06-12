//
// Created by homsl on 2020/4/14.
//
int trailingZeroes(int n) {
    if(n < 5)
        return 0;
    int num5 = 0;
    // trailing zero depends on 10 = 2*5
    // find 5 since 2 is always enough
    long long temp = 5;
    while(n/temp){
        num5 += n/temp;
        temp *= 5;
    }
    return num5;
}
