//
// Created by homsl on 2020/5/11.
//
// BFS
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(!root)
        return res;
    auto q = new queue<TreeNode*>;
    auto q1 = new queue<TreeNode*>;
    q->push(root);
    res.push_back(root->val);
    int rightmost = 0;
    bool flag = false;
    while(!q->empty()){
        TreeNode* cur = q->front();
        q->pop();
        if(cur->left){
            flag = true;
            rightmost = cur->left->val;
            q1->push(cur->left);
        }
        if(cur->right){
            flag = true;
            rightmost = cur->right->val;
            q1->push(cur->right);
        }
        if(q->empty()){
            if(flag){
                res.push_back(rightmost);
                flag = false;
            }
            swap(q,q1);
        }
    }
    return res;
}

// DFS
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(!root)
        return res;
    helper(root, res, 0);
    return res;
}

void helper(TreeNode* root, vector<int>& res, int level){
    if(!root)
        return;
    if(level == res.size())
        res.push_back(root->val);
    helper(root->right, res, level+1);
    helper(root->left, res, level+1);
}
