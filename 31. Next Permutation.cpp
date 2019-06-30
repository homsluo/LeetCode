//
// Created by homsl on 2019/6/29.
//

void nextPermutation(vector<int>& nums) {
    if(nums.size() < 2)
        return;
    if(nums.size() == 2){
        swap(nums[0], nums[1]);
        return;
    }
    int i = nums.size()-2;
    while(i >= 0){
        if(nums[i] < nums[i+1])
            for(int j = nums.size()-1; j > i; j--)
                if(nums[j] > nums[i]){
                    swap(nums[i], nums[j]);
                    reverse(nums.begin()+i+1, nums.end());
                    return;
                }
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
    }
}