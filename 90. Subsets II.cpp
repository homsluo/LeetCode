//
// Created by homsl on 2019/7/21.
//
//---------------------------------------------------------------------------------------------------------//
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res = {{}};
    if(nums.size() < 2){
        res.push_back(nums);
        return res;
    }
    vector<int> path;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, res, path);
    return res;
}

void dfs(vector<int>& nums, int pos, vector<vector<int>>& res, vector<int>& path){
    if(pos == nums.size())
        return;
    for(int i = pos; i < nums.size(); i++){
        if(i == pos || nums[i] != nums[i-1]){
            path.push_back(nums[i]);
            res.push_back(path);
            dfs(nums, i+1, res, path);
            path.pop_back();
        }
    }
}
//------------------------------------------------------------------------------------------------------//
