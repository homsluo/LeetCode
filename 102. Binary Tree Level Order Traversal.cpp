//
// Created by homsl on 2020/2/19.
//
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> list;
        for(int i = 0; i < size; i++){
            TreeNode* temp = q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            list.push_back(temp->val);
            q.pop();
        }
        res.push_back(list);
    }
    return res;
}
