//
// Created by homsl on 2020/5/28.
//
int countDigitOne(int n) {
    /* From right to left, count each bit start from 0. eg: 4(2)0(1)1(0)
    a. if current bit = 0:  count = higher * (10^bit)
    40: 0   1   (1)         400:  0   1  0~9   (10)
     ^  1   1   (1)          ^    1   1  0~9   (10)
        2   1   (1)               2   1  0~9   (10)
        3   1   (1)               3   1  0~9   (10)
        ------------             -------------------
        4   1   (0)               4   1   0     (0)
        total 4*(1)               total 4*(10)

    b. if current bit = 1:  count = higher * (10^bit) + lower + 1
    41: 0   1   (1)         411:  0   1   0~9  (10)
     ^  1   1   (1)          ^    1   1   0~9  (10)
        2   1   (1)               2   1   0~9  (10)
        3   1   (1)               3   1   0~9  (10)
        -----------              ------------------
        4   1   (1)               4   1   0~1   (2)
        total 4*(1)+(1)           total 4*(10)+(2)

    c. if current bit > 1:  count = higher * (10^bit) + (10^bit) = (higher+1) * (10^bit)
    43: 0   1   (1)         433:  0   1   0~9  (10)
     ^  1   1   (1)          ^    1   1   0~9  (10)
        2   1   (1)               2   1   0~9  (10)
        3   1   (1)               3   1   0~9  (10)
        -----------               -----------------
        4   1   (1)               4   1   0~9  (10)
        total 4*(1)+(1)           total 4*(10)+(10)
    */
    long long high = n;
    int curb = 0;
    long long bit = 1;    // 10 ^ 0
    long long count = 0;
    while(high){
        curb = high%10;
        high /= 10;
        count += high * bit;
        if(curb == 1)
            count += n%bit+1;
        else if(curb > 1)
            count += bit;
        bit *= 10;
    }
    return count;
}
