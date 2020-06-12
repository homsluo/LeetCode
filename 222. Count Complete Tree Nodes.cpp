//
// Created by homsl on 2020/5/25.
//
int countNodes(TreeNode* root) {
    if(!root)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int count = 1;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
            count++;
        }
        if(temp->right){
            q.push(temp->right);
            count++;
        }
    }
    return count;
}

// Recursive
int countNodes(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    if(!root->right)
        return 2;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return 1+left+right;
}
