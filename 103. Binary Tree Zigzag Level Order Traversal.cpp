//
// Created by homsl on 2020/2/20.
//
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    list<TreeNode*> q;
    q.push_front(root);
    bool ltr = true;
    while(!q.empty()){
        vector<int> list;
        int size = q.size();
        if(ltr){
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                list.push_back(temp->val);
                if(temp->left)
                    q.push_back(temp->left);
                if(temp->right)
                    q.push_back(temp->right);
                q.pop_front();
            }
            ltr = false;
        }
        else{
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.back();
                list.push_back(temp->val);
                if(temp->right)
                    q.push_front(temp->right);
                if(temp->left)
                    q.push_front(temp->left);
                q.pop_back();
            }
            ltr = true;
        }
        res.push_back(list);
    }
    return res;
}
