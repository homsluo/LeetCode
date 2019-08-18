//
// Created by homsl on 2019/7/25.
//
TreeNode* BuildTree(vector<int>& preorder, int p_s, int p_e, vector<int>& inorder, int i_s, int i_e){
    TreeNode* root = new TreeNode(preorder[p_s]);
    int pos = distance(inorder.begin(), find(inorder.begin()+i_s, inorder.begin()+i_e, preorder[p_s]));
    int l_size = pos - i_s, r_size = i_e - pos;
    if(l_size)
        root->left = BuildTree(preorder, p_s+1, p_s+l_size, inorder, i_s, pos-1);
    if(r_size)
        root->right = BuildTree(preorder, p_s+l_size+1, p_s+l_size+r_size, inorder, pos+1, i_e);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    if(!preorder.size)
        return nullptr;
    return BuildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}
