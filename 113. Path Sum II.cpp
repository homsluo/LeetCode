//
// Created by homsl on 2020/2/29.
//
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if(!root)
        return res;
    vector<int> path;
    helper(res, path, root, sum);
    return res;
}

void helper(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum){
    if(!root)
        return;
    if(!root->left && !root->right){
        if(root->val == sum){
            res.push_back(path);
            res.back().push_back(sum);
        }
        return;
    }

    path.push_back(root->val);
    helper(res, path, root->left, sum-root->val);
    helper(res, path, root->right, sum-root->val);
    path.pop_back();
}
