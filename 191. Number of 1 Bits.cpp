//
// Created by homsl on 2020/5/6.
//
int hammingWeight(uint32_t n) {
    if(!n)
        return 0;
    int count = 0;
    while(n != 0){
        n &= (n-1);
        count++;
    }
    return count;
}
