//
// Created by homsl on 2020/2/29.
//
void flatten(TreeNode* root) {
    if(!root)
        return;

    //inorder
    flatten(root->left);
    flatten(root->right);

    if(!root->left)
        return;
    TreeNode* temp = root->left;
    //First
    //Find the left left node
    while(temp->right)
        temp = temp->right;
    //Connect with right branch
    temp->right = root->right;
    //Second
    root->right = root->left;
    //Last
    root->left = nullptr;
}
