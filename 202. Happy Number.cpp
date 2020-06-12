//
// Created by homsl on 2020/4/9.
//
bool isHappy(int n) {
    unordered_set<int> exist;
    while(!exist.count(n)){
        exist.insert(n);
        n = sosq(n);
        if(n == 1)
            return true;
    }
    return false;
}

int sosq(int n){
    if(n < 10)
        return n*n;
    int sum = 0;
    while(n){
        int temp = n%10;
        sum += temp*temp;
        n /= 10;
    }
    return sum;
}
