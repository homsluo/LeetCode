//
// Created by homsl on 2020/6/12.
//
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> _m;
    for(int i = 0; i < nums.size(); i++)
        _m[nums[i]] = i;
    for(int i = 0; i < nums.size(); i++){
        if(_m.count(target-nums[i]) && _m[target-nums[i]] != i)
            return {i, _m[target-nums[i]]};
    }
    return {};
}
