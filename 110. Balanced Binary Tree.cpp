//
// Created by homsl on 2020/2/27.
//
bool isBalanced(TreeNode* root) {
    if(!root)
        return true;
    return(helper(root) != -1);
}

int helper(TreeNode* root){
    if(!root)
        return 0;
    int leftDepth = helper(root->left);
    int rightDepth = helper(root->right);
    if(leftDepth == -1 || rightDepth == -1)
        return -1;
    if(abs(leftDepth-rightDepth) > 1)
        return -1;
    return (max(leftDepth, rightDepth)+1);
}
