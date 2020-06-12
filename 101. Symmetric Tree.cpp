//
// Created by homsl on 2020/2/19.
//
bool isSymmetric(TreeNode* root) {
    if(!root)
        return true;
    return helper(root->left, root->right);
}
bool helper(TreeNode* left, TreeNode* right){
    if(!left && !right)
        return true;
    if(!left || !right)
        return false;
    return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}
