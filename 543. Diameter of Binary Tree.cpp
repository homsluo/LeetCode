//
// Created by homsl on 2020/4/11.
//
int diameterOfBinaryTree(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 0;
    int ans = 0;
    maxDiameter(root, ans);
    return ans;
}

int maxDiameter(TreeNode* root, int& ans){
    if(!root)
        return 0;
    int maxleft = maxDiameter(root->left, ans);
    int maxright = maxDiameter(root->right, ans);
    ans = max(maxleft+maxright, ans);
    return max(maxleft, maxright)+1;
}
