//
// Created by homsl on 2020/3/27.
//
vector<int> preorderTraversal(TreeNode* root) {
    if(!root)
        return {};

    vector<int> ans;
    helper(ans, root);
    return ans;
}

void helper(vector<int>& ans, TreeNode* root){
    if(!root)
        return;

    ans.push_back(root->val);
    helper(ans, root->left);
    helper(ans, root->right);
}

//-----------------------------------------------------------------------------------------------------
vector<int> preorderTraversal(TreeNode* root) {
    if(!root)
        return {};

    vector<int> ans;
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    while(!q.empty() || !s.empty()){
        TreeNode* temp;
        if(!q.empty()){
            temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        else{
            temp = s.top();
            s.pop();
            ans.push_back(temp->val);
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            s.push(temp->right);
    }
    return ans;
}
