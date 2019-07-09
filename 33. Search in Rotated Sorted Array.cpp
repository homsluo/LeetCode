//
// Created by homsl on 2019/7/1.
//
int search(vector<int>& nums, int target) {
    if(nums.size() < 1)
        return -1;
    if(target <= nums[nums.size()-1]){
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < target)
                return -1;
            else if(nums[i] == target)
                return i;
        }
    }
    else if(target >= nums[0]){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > target)
                return -1;
            else if(nums[i] == target)
                return i;
        }
    }
    else if(target < nums[0] && target > nums[nums.size()-1])
        return -1;
    return -1;
}

int search(vector<int>& nums, int target) {    // Binary Search
    if(nums.size() < 1)
        return -1;
    int left = 0, right = nums.size()-1, n = nums.size()-1;
    while(left < right){
        int mid = (left+right)/2;
        if(nums[left] == target)
            return left;
        if(nums[right] == target)
            return right;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > nums[left]){
            if(target > nums[mid])
                left = mid+1;
            else{
                if(target > nums[left])
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        else{
            if(target < nums[mid])
                right = mid-1;
            else{
                if(target < nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
    }
    if(nums[left] == target)
        return left;
    else
        return -1;
}
