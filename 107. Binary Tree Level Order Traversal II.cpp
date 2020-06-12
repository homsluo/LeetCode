//
// Created by homsl on 2020/2/21.
//
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> list;
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* temp = q.front();
            list.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            q.pop();
        }
        res.insert(res.begin(), list);
    }
    return res;
}
