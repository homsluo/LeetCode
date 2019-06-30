//
// Created by homsl on 2019/6/24.
//

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, ans = 0, i = 0;
    while(i < nums.size()){
        if(nums[i] == 1){
            while(i < nums.size() && nums[i] == 1){
                count++;
                i++;
            }
            ans = max(ans, count);
            count = 0;
        }
        i++;
    }
    return ans;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxhere = 0, ans = 0;
    for(int n:nums){
        ans = max(ans, maxhere = n == 0 ? 0 : maxhere+1);
    }
    return ans;
}

