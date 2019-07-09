//
// Created by homsl on 2019/7/2.
//

vector<int> searchRange(vector<int>& nums, int target) {
    int i = 0, j = nums.size()-1;
    vector<int> ans = {-1, -1};
    if(nums.size() < 1)
        return ans;
    if(nums[j] < target)
        return ans;
    while(i < j){
        while(nums[i] < target && i < j)
            i++;
        while(nums[j] > target && i < j)
            j--;
        if(nums[i] >= target && nums[j] <= target)
            break;
        if(i >= j)
            break;
    }
    if(nums[i] == nums[j] && nums[i] == target){
        ans[0] = i;
        ans[1] = j;
    }
    return ans;
}