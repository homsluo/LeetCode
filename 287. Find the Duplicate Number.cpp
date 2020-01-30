//
// Created by homsl on 2019/8/22.
//
int findDuplicate(vector<int>& nums) {
    if(nums.size() < 2)
        return 1;
    int l = 1, r = nums.size()-1;
    while(l < r){
        int mid = (l+r)/2;
        int sum = 0;
        for(int i = mid; i > 0; i--)
            sum += count(nums.begin(), nums.end(), i);
        if(sum <= mid)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
// Find circle and entry!!!
int findDuplicate(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    int slow = nums[0];
    int fast = nums[nums[0]];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    int entry = 0;
    while(entry != slow){
        entry = nums[entry];
        slow = nums[slow];
    }
    return entry;
}
