//
// Created by homsl on 2020/2/2.
//
int mySqrt(int x) {
    int left = 0;
    int right = int(sqrt(INT32_MAX));
    while(right-left > 1){
        int mid = (left+right)/2;
        if(mid*mid > x)
            right = mid;
        else if(mid*mid < x)
            left = mid;
        else
            return mid;
    }
    if(right*right <= x)
        return right;
    return left;
}

//------------------------------------------
int mySqrt(int x) {
    int cur = 0;
    int count = 0;
    int add = 1;
    while(cur <= x){
        if(INT32_MAX-cur < add)
            return count;
        cur += add;
        add += 2;
        count++;
    }
    return count-1;
}
