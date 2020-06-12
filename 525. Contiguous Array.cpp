//
// Created by homsl on 2020/4/13.
//
int findMaxLength(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    unordered_map<int, int> presum;
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i]?1:-1;
        if(sum == 0)
            ans = i+1;
        else if(presum.count(sum))
            ans = max(ans, i-presum[sum]);
        else
            presum[sum] = i;
    }
    return ans;
}
