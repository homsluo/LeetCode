//
// Created by homsl on 2020/1/11.
//
int firstMissingPositive(vector<int>& nums) {
    if(nums.empty())
        return 1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 1)
            nums[i] = INT32_MAX;
    }
    for(int i = 0; i < nums.size(); i++){
        int n = abs(nums[i]);
        if(n-1 < nums.size())
            nums[n-1] = -abs(nums[n-1]);
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0)
            return i+1;
    }
    return nums.size()+1;
}
