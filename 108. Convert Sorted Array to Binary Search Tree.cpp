//
// Created by homsl on 2020/2/24.
//
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty())
        return nullptr;
    TreeNode* root = build(nums, 0, nums.size()-1);
    return root;
}

TreeNode* build(vector<int>& nums, int l, int r){
    if(l > r)
        return nullptr;
    int mid = (l+r)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, l, mid-1);
    root->right = build(nums, mid+1, r);
    return root;
}
