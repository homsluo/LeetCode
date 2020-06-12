//
// Created by homsl on 2020/2/13.
//
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root)
        return res;
    inorder(root, res);
    return res;
}

void inorder(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
