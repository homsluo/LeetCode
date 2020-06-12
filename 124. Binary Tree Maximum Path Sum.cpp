//
// Created by homsl on 2020/3/4.
//
int maxPathSum(TreeNode* root) {
    if(!root)
        return 0;
    int ans = INT32_MIN;
    helper(root, ans);
    return ans;
}

int helper(TreeNode* root, int& ans){
    if(!root)
        return 0;
    int l = max(0, helper(root->left, ans));
    int r = max(0, helper(root->right, ans));

    ans = max(ans, root->val + l + r);
    return max(l,r)+root->val;
}
