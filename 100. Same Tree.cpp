//
// Created by homsl on 2020/2/19.
//
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!q && !p)
        return true;
    if(!q || !p)
        return false;
    if(p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
