//
// Created by homsl on 2020/4/15.
//
class BSTIterator {
private:
    stack<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stack.top();
        stack.pop();
        push(cur->right);
        return cur->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

    void push(TreeNode* root){
        for(; root; root = root->left)
            stack.push(root);
    }
};
