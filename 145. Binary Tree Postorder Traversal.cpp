//
// Created by homsl on 2020/3/27.
//
vector<int> postorderTraversal(TreeNode* root) {
    if(!root)
        return {};

    queue<TreeNode*> q;
    stack<TreeNode*> s;
    deque<int> d_ans;

    q.push(root);
    while(!q.empty() || !s.empty()){
        TreeNode* temp;
        if(!q.empty()){
            temp = q.front();
            q.pop();
            d_ans.push_front(temp->val);
        }
        else{
            temp = s.top();
            s.pop();
            d_ans.push_front(temp->val);
        }
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
    vector<int> ans(d_ans.begin(), d_ans.end());
    return ans;
}
