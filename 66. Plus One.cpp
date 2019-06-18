//
// Created by homsl on 2019/6/18.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits){
    int len = digits.size();
    if(len == 0)
        return digits;
    int i = len-1;

    while(i >= 0){
        if(digits[i] == 9){
            digits[i] = 0;
            if(i == 0){
                auto temp = digits.insert(begin(digits), 1);
                return digits;
            }
            else
                i--;
        }
        else{
            digits[i] += 1;
            return digits;
        }
    }
    return digits;
}
