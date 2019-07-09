//
// Created by homsl on 2019/7/4.
//
void backtracking(int start, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans){
    if(!target){
        ans.push_back(temp);
        return;
    }
    for(int i = start; i < candidates.size() && target >= candidates[i]; i++){
        if(i == start || candidates[i] != candidates[i-1]){
            temp.push_back(candidates[i]);
            backtracking(i+1, target-candidates[i], candidates, temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    backtracking(0, target, candidates, temp, ans);
    return ans;
}
