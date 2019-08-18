//
// Created by homsl on 2019/8/9.
//
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    if(!k)
        return res;
    vector<int> path;
    int sum = 0;
    dfs(res, path, k, n, sum, 1);
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& path, int k, int n, int sum, int start){
    if(sum < n && path.size() == k)
        return;
    if(sum == n && path.size() == k){
        res.push_back(path);
        return;
    }
    for(int i = start; i <= 9 && (sum+start) <= n; i++){
        path.push_back(i);
        sum += i;
        dfs(res, path, k, n, sum, i+1);
        path.pop_back();
        sum -= i;
    }
}
