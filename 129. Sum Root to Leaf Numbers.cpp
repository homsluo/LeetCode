//
// Created by homsl on 2020/3/16.
//
int sumNumbers(TreeNode* root) {
    if(!root)
        return 0;
    int res = 0;
    helper(root, res, 0);
    return res;
}

void helper(TreeNode* root, int& res, int sum){
    if(!root->left && !root->right){
        res += sum*10+root->val;
        return;
    }

    if(root->left){
        helper(root->left, res, sum*10+root->val);
    }
    if(root->right){
        helper(root->right, res, sum*10+root->val);
    }
}
