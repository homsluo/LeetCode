//
// Created by homsl on 2020/1/19.
//
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() < 1)
        return res;
    if(nums.size() == 1){
        res.push_back(nums);
        return res;
    }
    vector<bool> used(nums.size(), false);
    vector<int> path;
    dfs(res, nums, used, path);
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& nums, vector<bool>& used, vector<int>& path){
    if(path.size() == nums.size())
        res.push_back(path);
    for(int i = 0; i < nums.size(); i++){
        if(!used[i]){
            path.push_back(nums[i]);
            used[i] = true;
            dfs(res, nums, used, path);
            used[i] = false;
            path.pop_back();
        }
    }
}
