//
// Created by homsl on 2019/6/22.
//
int missingNumber(vector<int>& nums) { // (sum from 1 to n) - (sum of array) = missing number
    int n = nums.size();
    int sum = (1+n)*n/2;
    for(int i = 0; i < nums.size(); i++)
        sum -= nums[i];
    return sum;
}
