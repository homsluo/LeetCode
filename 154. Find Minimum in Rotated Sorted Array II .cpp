//
// Created by homsl on 2020/4/7.
//

// Best case O(logn) like 153
// Worst case O(n)
int findMin(vector<int>& nums) {
    int len = nums.size();
    if(len == 1)
        return nums[0];
    return find(nums, 0, len-1);
}

int find(vector<int>& nums, int left, int right){
    if(left+1 >= right)
        return min(nums[left], nums[right]);

    if(nums[left] < nums[right])
        return nums[left];

    int mid = (left+right)/2;

    return min(find(nums, left, mid), find(nums, mid+1, right));
}
