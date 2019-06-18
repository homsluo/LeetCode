//
// Created by homsl on 2019/6/13.
//
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int reverse(int x){
    int ans = 0, temp = 0;
    while(x){
        temp = ans * 10 + x % 10;
        if(temp/10 != ans)
            return 0;
        ans = temp;
        x = x/10;
    }
    return ans;
}
#if 0
int reverse(int x){
    int rev = 0, pop = 0;
    while(x){
        pop = x % 10;
        x = x/10;
        if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7))
            return 0;
        if(rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8))
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}
#endif

int main(){
    int a = 1534236469;
    cout << reverse(a);
}
