//
// Created by homsl on 2020/1/18.
//
int jump(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    int curreach = 0;
    int nextreach = 0;
    int step = 0;
    int idx = 0;
    while(idx <= curreach){
        while(idx <= curreach){
            nextreach = max(nextreach, idx+nums[idx]);
            idx++;
        }
        curreach = nextreach;
        step++;
        if(curreach >= nums.size()-1)
            return step;
    }
    return 0;
}
