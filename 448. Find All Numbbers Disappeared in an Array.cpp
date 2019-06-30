//
// Created by homsl on 2019/6/23.
//
vector<int> findDisappearedNumbers(vector<int>& nums) {  // sort the array from small to large. then compare with index.
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1]);
            i--;
        }
    }
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i+1){
            ans.push_back(i+1);
        }
    }
    return ans;
}


vector<int> findDisappearedNumbers(vector<int>& nums) {     // existed numbers' position will have a negative number.
    for(int i = 0; i < nums.size(); i++){
        if(nums[abs(nums[i])-1] > 0)
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
    }
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0)
            ans.push_back(i+1);
    }
    return ans;
}