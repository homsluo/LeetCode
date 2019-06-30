//
// Created by homsl on 2019/6/21.
//
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> arr;
    for(int i = 0; i < nums.size(); i++){
        if(arr.find(nums[i]) != arr.end()){
            if(i - arr[nums[i]] <= k)
                return true;
            else
                arr[nums[i]] = i;
        }
        else
            arr[nums[i]] = i;
    }
    return false;
}
