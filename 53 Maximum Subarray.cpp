//
// Created by homsl on 2019/6/17.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#if 0
int maxSubArray(vector<int>& nums){
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int max_num = nums[0];
    int i = 1;
    for(; i < nums.size(); i++){
        if(dp[i-1] < 0)
            dp[i] = nums[i];
        else
            dp[i] = dp[i-1] + nums[i];
        max_num = max(dp[i], max_num);
    }
    return max_num;
}
#endif

int maxSubSumRec(vector<int>& nums, int l, int r){
    if(l >= r)
        return nums[l];
    int mid;
    mid = (l+r)/2;
    int lmax = maxSubSumRec(nums, l, mid-1);
    int rmax = maxSubSumRec(nums, mid+1, r);
    int midmax = nums[mid], t = midmax;

    for(int i = mid-1; i >= l; i--){
        t += nums[i];
        midmax = max(t, midmax);
    }

    t = midmax;
    for(int i = mid+1; i <= r; i++){
        t += nums[i];
        midmax = max(t, midmax);
    }

    return max(midmax, max(lmax, rmax));
}

int maxSubArray(vector<int>& nums){
    return maxSubSumRec(nums, 0, nums.size()-1);
}