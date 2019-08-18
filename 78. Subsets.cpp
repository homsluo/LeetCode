//
// Created by homsl on 2019/7/16.
//
vector<vector<int>> subsets(vector<int>& nums) {   bit &
    vector<vector<int>> res;
    int n = nums.size();
    int all = 1 << n;

    for(int i = 0; i < all; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            if((i & (1<<j)) != 0)
                temp.push_back(nums[j]);
        }
        res.push_back(temp);
    }
    return res;
}

//------------------------------------------------------------------//
vector<vector<int>> subsets(vector<int>& nums) {    dfs
    vector<vector<int>> res;
    vector<int> path;
    res.push_back(path);
    if(nums.size() == 0)
        return res;
    dfs(nums, 0, res, path);
    return res;
}

void dfs(vector<int>& nums, int pos, vector<vector<int>>& res, vector<int>& path){
    if(pos == nums.size())
        return;
    for(int i = pos; i < nums.size(); i++){
        path.push_back(nums[i]);
        res.push_back(path);
        dfs(nums, i+1, res, path);
        path.pop_back();
    }
}
//----------------------------------------------------------------------------//