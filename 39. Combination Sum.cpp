//
// Created by homsl on 2019/7/4.
//
void backtracking(int start, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target){
    if(!target){
        ans.push_back(temp);
        return;
    }

    for(int i = start; i < candidates.size() && target >= candidates[i]; i++){
        temp.push_back(candidates[i]);
        backtracking(i, candidates, temp, ans, target-candidates[i]);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    sort(candidates.begin(), candidates.end());
    backtracking(0, candidates, temp, ans, target);

    return ans;
}
