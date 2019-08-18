//
// Created by homsl on 2019/7/15.
//
void sortColors(vector<int>& nums) {  // insertion sort
    int n = nums.size();
    if(n < 2)
        return;
    for(int i = 1; i < n; i++){
        int j = i-1;
        int temp = nums[i];
        while(j >= 0 && nums[j] > temp){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
}

void sortColors(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
        return;
    int L = -1, R = n;
    int i = 0;
    while(i < R){
        if(nums[i] < 1)
            swap(nums[i++], nums[++L]);
        else if(nums[i] > 1)
            swap(nums[i], nums[--R]);
        else
            i++;
    }
}

void sortColors(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
        return;
    int i = -1, j = -1, k = -1;
    for(int m = 0; m < n; m++){
        if(nums[m] == 0){
            nums[++k] = 2;
            nums[++j] = 1;
            nums[++i] = 0;
        }
        else if(nums[m] == 1){
            nums[++k] = 2;
            nums[++j] = 1;
        }
        else
            nums[++k] = 2;
    }
}
