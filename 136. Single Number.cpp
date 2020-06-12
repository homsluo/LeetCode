//
// Created by homsl on 2020/3/25.
//
// XOR
int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int num:nums){
        res ^= num;
    }
    return res;
}
