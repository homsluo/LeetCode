//
// Created by homsl on 2019/8/30.
//
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    if(nums.size() < 2)
        return res;
    for(int i = 0; i < nums.size(); i++){
        nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1] > 0)
            res.push_back(abs(nums[i]));
    }
    return res;
}

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    if(nums.size() < 2)
        return res;
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i-1])
            res.emplace_back(nums[i]);
    }
    return res;
}
