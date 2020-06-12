//
// Created by homsl on 2020/2/29.
//
bool hasPathSum(TreeNode* root, int sum) {
    if(!root)
        return false;
    return helper(root, sum, 0);
}

bool helper(TreeNode* root, int sum, int cur){
    if(!root)
        return (cur == sum);
    cur += root->val;
    if(!root->left)
        return helper(root->right, sum, cur);
    else if(!root->right)
        return helper(root->left, sum, cur);
    return (helper(root->left, sum, cur) || helper(root->right, sum, cur));
}
