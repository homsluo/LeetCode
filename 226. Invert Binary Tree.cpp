//
// Created by homsl on 2020/5/26.
//
TreeNode* invertTree(TreeNode* root) {
    if(!root || (!root->left && !root->right))
        return root;
    if(root->left)
        invertTree(root->left);
    if(root->right)
        invertTree(root->right);
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    return root;
}
