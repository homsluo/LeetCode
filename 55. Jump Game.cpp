//
// Created by homsl on 2019/7/6.
//
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxreach = 0;
    for(int i = 0; i != n; i++){
        if(i > maxreach)
            return false;
        maxreach = max(maxreach, i+nums[i]);
        if(maxreach >= n-1)
            return true;
    }
    return false;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
        return true;
    bool arr[n] = {false};
    for(int i = n-2; i >= 0; i--){
        if(i+nums[i] >= n-1)
            arr[i] = true;
        else
            for(int j = 1; j <= nums[i]; j++)
                if(arr[i+j])
                    arr[i] = true;
    }
    return arr[0];
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
        return true;
    int end = n-1;
    int start = end-1;
    for(;start > 0; start--){
        if(nums[start] + start >= end)
            end = start;
    }
    return (start+nums[start] >= end);
}
