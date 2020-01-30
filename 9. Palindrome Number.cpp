//
// Created by homsl on 2019/10/7.
//

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int copy = x;
    int count = 0;
    while(copy != 0){
        count++;
        copy = copy/10;
    }
    copy = x;
    long long int bac = 0;
    while(count > 0){
        bac = bac*10 + copy%10;
        copy /= 10;
        count--;
    }
    return bac == x ? true : false;
}

//- ---------------------------------------------------------------
bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int copy = x;
    long long int bac = 0;
    while(copy != 0){
        bac = bac*10 + copy%10;
        copy /= 10;
    }
    return bac == x ? true : false;
}