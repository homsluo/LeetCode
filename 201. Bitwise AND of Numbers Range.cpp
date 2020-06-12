//
// Created by homsl on 2020/4/25.
//
int rangeBitwiseAnd(int m, int n) {
    int count = 0;
    while(m != n){
        m >>= 1;
        n >>= 1;
        count++;
    }
    return (m << count);
}
