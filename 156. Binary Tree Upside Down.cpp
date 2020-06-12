//
// Created by homsl on 2020/4/8.
//
/*Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
           1
          / \
         2   3
        / \
       4   5

return the root of the binary tree [4,5,2,#,#,3,1].
            4
           / \
          5   2
             / \
            3   1
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root){
        if(!root || (!root->left && !root->right))
            return root;

        TreeNode* parent = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left){
            TreeNode* res = upsideDownBinaryTree(left);
            res->left = right;
            res->right = parent;
            return parent;
        }
        return root;
    }
};