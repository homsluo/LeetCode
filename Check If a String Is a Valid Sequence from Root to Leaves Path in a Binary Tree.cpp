//
// Created by homsl on 2020/5/1.
//
/* Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree.

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

Example 1:
Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation:
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure).
Other valid sequences are:
0 -> 1 -> 1 -> 0
0 -> 0 -> 0
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!root && arr.empty())
            return true;
        if(!root || arr.empty())
            return false;
        return isSub(root, arr, 0);
    }

    bool isSub(TreeNode* root, vector<int>& arr, int pos){
        if(root->val != arr[pos])
            return false;
        cout << "root->val: " << root->val << ' ' << "pos: " << pos << '\n';
        if(pos == arr.size()-1)
            return (!root->left && !root->right);
        bool left;
        bool right;
        if(root->left){
            left = isSub(root->left, arr, pos+1);
        }
        if(root->right){
            right = isSub(root->right, arr, pos+1);
        }
        cout << (left||right);
        return (left||right);
    }
};