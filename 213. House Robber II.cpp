//
// Created by homsl on 2019/9/24.
//

int rob(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.empty()? 0: nums[0];
    return max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1));
}

int rob(vector<int>& nums, int left, int right){
    if(right - left < 1)
        return nums[left];
    if(right - left == 1)
        return max(nums[left], nums[left+1]);
    vector<int>dp(nums.size()-1, 0);
    dp[0] = nums[left];
    dp[1] = max(nums[left], nums[left+1]);
    for(int i = 2; i < dp.size(); i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i+left]);
    }
    return dp[nums.size()-2];
}