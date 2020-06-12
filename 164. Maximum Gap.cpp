//
// Created by homsl on 2020/4/10.
//
int maximumGap(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    set<int> sorted;
    for(int num:nums){
        sorted.insert(num);
    }
    int res = 0;
    int prev = *sorted.begin();
    for(int num:sorted){
        res = max(num-prev, res);
        prev = num;
    }
    return res;
}
