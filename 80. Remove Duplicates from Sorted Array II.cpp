//
// Created by homsl on 2019/7/18.
//
int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 3)
        return nums.size();
    int i = 0;
    for(int j = 0; j < nums.size(); j++){
        if(nums[j] != nums[i]){
            if(j-i > 1){
                nums.erase(nums.begin()+i, nums.begin()+j-2);
                j -= (j-i-2);
            }
            i = j;
        }
    }
    if(nums.size()-i>1)
        nums.resize(nums.size()-(nums.size()-i-2));
    return nums.size();
}

int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 3)
        return nums.size();
    for(int i = 0; i < nums.size()-2;){
        if(nums[i] == nums[i+1] && nums[i] == nums[i+2])
            nums.erase(nums.begin()+i+2, nums.begin()+i+3);
        else
            i++;
    }
    return nums.size();
}
