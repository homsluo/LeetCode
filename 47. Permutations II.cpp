//
// Created by homsl on 2020/1/19.
//
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() < 1)
        return res;
    if(nums.size() < 2){
        res.push_back(nums);
        return res;
    }
    sort(nums.begin(), nums.end());
    vector<int> path;
    vector<bool> used(nums.size(), false);
    dfs(res, nums, path, used);
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, vector<bool>& used){
    if(path.size() == nums.size())
        res.push_back(path);
    else{
        int preNum = nums[0]-1;
        for(int i = 0; i < nums.size(); i++){
            if(!used[i] && nums[i] != preNum){
                path.push_back(nums[i]);
                preNum = nums[i];
                used[i] = true;
                dfs(res, nums, path, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
}
