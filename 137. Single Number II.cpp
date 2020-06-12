//
// Created by homsl on 2020/3/25.
//
int singleNumber(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];

    int res = 0;
    for(int i = 0; i < 32; i++){
        int sum = 0;
        for(int num:nums){
            sum += (num >> i) & 1;
            sum %= 3;
        }
        res |= (sum << i);
    }
    return res;
}
