//
// Created by homsl on 2019/6/21.
//
bool containsDuplicate(vector<int>& nums) { // hash table brute force
    if(nums.size() <= 1)
        return false;
    unordered_map<int, int> numbers;
    for(int i = 0; i < nums.size(); i++){
        if(numbers.find(nums[i]) != numbers.end())
            return true;
        else
            numbers[nums[i]] = 1;
    }
    return false;
}
