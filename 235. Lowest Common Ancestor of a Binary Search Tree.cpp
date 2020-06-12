//
// Created by homsl on 2020/5/29.
//
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
        return nullptr;
    if(root == p || root == q)
        return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(!left && !right)
        return nullptr;
    if(left && right)
        return root;
    return left?left:right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}