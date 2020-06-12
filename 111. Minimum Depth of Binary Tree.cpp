//
// Created by homsl on 2020/2/27.
//
int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left)
        return minDepth(root->right)+1;
    else if(!root->right)
        return minDepth(root->left)+1;
    return min(minDepth(root->left), minDepth(root->right))+1;
}
