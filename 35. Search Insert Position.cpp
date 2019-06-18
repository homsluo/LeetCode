//
// Created by homsl on 2019/6/17.
//
#include <iostream>
#include <vector>
using namespace std;
#if 0
int searchInsert(vector<int>& nums, int target) {
    int i = nums.size()/2, L = 0, R = nums.size()-1;
    while(L <= R){
        if(nums[i] < target){
            if(i+1 < nums.size() && nums[i+1] > target)
                return i+1;
            L = i;
            i = (R+L)/2;
        }
        else if(nums[i] > target){
            if(i-1 > 0 && nums[i-1] < target)
                return i-1;
            R = i;
            i = (R+L)/2;
        }
        else
            return i;
    }
//    return i;
}
#endif
int searchInsert(vector<int>& nums, int target) {
    int i = 0;
    for(int j = 0; j < nums.size(); j++){
        if(nums[j] < target)
            i++;
        else
            break;
    }
    return i;
}

int main(){
    vector<int> p;
    p.push_back(1);
    p.push_back(3);
    p.push_back(5);
    p.push_back(6);
    cout << searchInsert(p, 5);
}