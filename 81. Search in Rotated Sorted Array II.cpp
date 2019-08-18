//
// Created by homsl on 2019/7/21.
//
bool search(vector<int>& nums, int target) {
    if(nums.size() < 1)
        return false;
    int l = 0, r = nums.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(target == nums[l] || target == nums[mid] || target == nums[r])
            return true;
        else if(nums[l] == nums[mid] && nums[l] == nums[r])
            r--;
        else if(target < nums[mid]){
            if(nums[mid] >= nums[l] && nums[l] >= nums[r] && target < nums[r])
                l = mid+1;
            else
                r = mid-1;
        }
        else{
            if(nums[mid] < nums[l] && target > nums[l])
                r = mid-1;
            else
                l = mid+1;
        }
    }
    return false;
}
