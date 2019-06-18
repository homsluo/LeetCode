//
// Created by homsl on 2019/6/13.
//
#include <iostream>
#include <vector>
using namespace std;

#if 0
int removeDuplicates(vector<int>& nums){
    int len = nums.size();
    for(int i = 0; i < len-1; i++){
        if(nums[i] == nums[i+1]) {
            auto iter = nums.erase(begin(nums) + i);
            i--;
            len--;
        }
    }
    return len;
}
#endif

int removeDuplicates(vector<int>& nums){
    int k = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[k])
            nums[++k] = nums[i];
    }
    nums.resize(k+1);
    return k+1;
}
