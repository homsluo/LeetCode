//
// Created by homsl on 2019/6/25.
//
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.size() < 3)
        return ans;
    sort(nums.begin(), nums.end());
    if(nums[0] > 0 || nums[nums.size()-1] < 0)
        return ans;

    for(int i = 0; i < nums.size()-2; i++){
        int j = i+1;
        int k = nums.size()-1;
        while(j < k){
            if(nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if(nums[i] + nums[j] + nums[k] > 0)
                k--;
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                while(j < nums.size() && nums[j-1] == nums[j])
                    j++;
            }
        }
        while(i < nums.size()-2 && nums[i+1] == nums[i])
            i++;
    }
    return ans;
}
