//
// Created by homsl on 2020/5/6.
//
uint32_t reverseBits(uint32_t n) {
    if(!n)
        return 0;
    int res = 0;
    for(int i = 0; i < 32; i++){
        res <<= 1;
        if(n&1 == 1)
            res += 1;
        n >>= 1;
    }
    return res;
}
