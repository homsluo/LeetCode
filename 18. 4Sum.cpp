//
// Created by homsl on 2019/6/28.
//
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.size() < 4)
        return ans;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size()-3; i++){
        if(nums[i]*4 > target)
            break;
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        for(int j = nums.size()-1; j > i+2; j--){
            if(nums[j]*4 < target)
                break;
            if(j < nums.size()-1 && nums[j] == nums[j+1])
                continue;

            int l = i+1, r = j-1;
            while(l < r){
                if(nums[i]+nums[l]+nums[r]+nums[j] == target){
                    ans.push_back({nums[i],nums[l],nums[r],nums[j]});
                    while(l < r && nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;
                    l++,r--;
                }
                else if(nums[i]+nums[l]+nums[r]+nums[j] < target)
                    l++;
                else
                    r--;
            }
        }
    }
    return ans;
}
