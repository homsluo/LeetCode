//
// Created by homsl on 2019/7/25.
//
TreeNode* BuildTree(vector<int>& inorder, int i_s, int i_e, vector<int>& postorder, int p_s, int p_e){
    TreeNode* root = new TreeNode(postorder[p_e]);
    int pos = distance(inorde.begin(), find(inorder.begin()+i_s, inorder.begin()+i_e, postorder[p_e]));
    int l_size = pos-i_s, r_size = i_e-pos;
    if(r_size)
        root->right = BuildTree(inorder, pos+1, pos+r_size, postorder, p_e-r_size, p_e-1);
    if(l_size)
        root->left = BuildTree(inorder, pos-l_size, pos-1, postorder, p_e-r_size-l_size, p_e-r_size-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    if(!inorder.size())
        return nullptr;
    return BuildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}
