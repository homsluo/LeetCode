//
// Created by homsl on 2020/2/17.
//
bool isValidBST(TreeNode* root) {
    if(!root)
        return true;
    return recur(root, 0, 0, false, false);
}

bool recur(TreeNode* root, int minv, int maxv, bool minex, bool maxex){
    if(!root)
        return true;
    if((maxex && root->val >= maxv)||(minex && root->val <= minv))
        return false;
    bool left = recur(root->left, minv, root->val, minex, true);
    bool right = recur(root->right, root->val, maxv, true, maxex);
    return left&&right;
}
