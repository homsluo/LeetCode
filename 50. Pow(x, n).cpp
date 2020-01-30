    //
// Created by homsl on 2020/1/22.
//
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(x == 1.0)
            return x;
        if(x == -1.0)
            return (n % 2 == 0)? -x : x;
        int sign = (n > 0) ? 0 : 1;
        double prod = 1;
        if(n == INT32_MIN){
            prod = x;
            n++;
        }
        n = abs(n);
        while(n > 1){
            if(n % 2 != 0){
                prod = prod*x;
                n--;
            }
            x = x*x;
            n = n/2;
        }
        x = prod*x;
        if(sign)
            x = 1.0/x;
        return x;
    }
