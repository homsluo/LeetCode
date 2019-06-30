//
// Created by homsl on 2019/6/20.
//

void rotate(vector<int>& nums, int k) {   // Brute Force
    for(int i = 0; i < k; i++){
        int temp = nums[nums.size()-1];
        for(int j = nums.size()-1; j > 0; j--)
            nums[j] = nums[j-1];
        nums[0] = temp;
    }
}

void rotate(vector<int>& nums, int k) {  // Extra Array
    vector<int> temp(nums.size(), 0);
    for(int i = 0; i < nums.size(); i++)
        temp[(i+k) % nums.size()] = nums[i];
    for(int j = 0; j < nums.size(); j++)
        nums[j] = temp[j];
}

void rotate(vector<int>& nums, int k){  // One Pass, O(n)
    int temp1, temp2, index, count = 0;
    int len = nums.size();
    k %= len;
    if(k == 0)
        return;
    for(int i = 0; i <= k; i++){
        if(count >= len)
            return;
        temp1 = nums[i];
        index = i;
        while((index+k)%len != i){
            temp2 = nums[(index+k)%len];
            nums[(index+k)%len] = temp1;
            temp1 = temp2;
            index = (index+k)%len;
            count++;
        }
        nums[i] = temp1;
        count++;
    }
}

void rotate(vector<int>& nums, int k) {  // 3 Steps Reverse O(n)
    int len = nums.size();
    k %= len;
    reverse(nums.begin(), nums.begin()+len-k);
    reverse(nums.begin()+len-k, nums.end());
    reverse(nums.begin(), nums.end());
}
