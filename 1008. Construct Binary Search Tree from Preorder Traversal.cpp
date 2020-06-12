//
// Created by homsl on 2020/4/20.
//
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.empty())
        return nullptr;
    TreeNode* root = helper(preorder, 0, preorder.size()-1);
    return root;
}

TreeNode* helper(vector<int>& preorder, int start, int end){
    if(start > end)
        return nullptr;
    TreeNode* root = new TreeNode(preorder[start]);
    if(start == end)
        return root;
    int split = start+1;
    while(split <= end && preorder[split] < preorder[start])
        split++;
    root->left = helper(preorder, start+1, split-1);
    root->right = helper(preorder, split, end);
    return root;
}
