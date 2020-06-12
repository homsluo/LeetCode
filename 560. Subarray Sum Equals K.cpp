//
// Created by homsl on 2020/4/24.
//
int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> prefixsum = {{0,1}};
    int sum = 0;
    for(int num:nums){
        sum += num;
        ans += prefixsum[sum-k];
        prefixsum[sum]++;
    }
    return ans;
}
