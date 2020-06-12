//
// Created by homsl on 2020/5/23.
//
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // Store all in a binary tree, search for each one's smalles larger one and largest smaller one
    if(nums.size() < 2 || k == 0 || t < 0)
        return false;
    set<long long> wd;
    for(int i = 0; i < nums.size(); i++){
        if(i > k) wd.erase(nums[i-k-1]);
        if(wd.count(nums[i]))   // if exist then return true;
            return true;
        // If not, insert it and search for lesser one and greater one
        wd.insert(nums[i]);
        // If have greater one and difference less than t
        if(++wd.find(nums[i]) != wd.end() && *(++wd.find(nums[i]))-nums[i] <= t)
            return true;
        // If have lesser one
        if(wd.find(nums[i]) != wd.begin() && nums[i]-*(--wd.find(nums[i])) <= t)
            return true;
    }
    return false;
}