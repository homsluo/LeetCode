//
// Created by homsl on 2020/1/7.
//

int divide(int dividend, int divisor) {
    if(divisor == 0) return INT32_MAX;
    if(dividend == INT32_MIN){
        if(divisor == 1) return INT32_MIN;
        if(divisor == -1) return INT32_MAX;
    }

    long a = (long)dividend, b = (long)divisor;
    bool sign = 1;
    if(a < 0){
        a = -a;
        sign = !sign;
    }
    if(b < 0){
        b = -b;
        sign = !sign;
    }
    int res = 0;
    while(a >= b){
        int shift = 0;
        while(a >= b << shift)
            shift++;
        res += 1 << (shift-1);
        a -= b<<(shift-1);
    }
    if(!sign)
        return -res;
    return res;
}