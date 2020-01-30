//
// Created by homsl on 2019/9/5.
//
vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
        return {};
    return *DFS(1,n);
}

vector<TreeNode*>* DFS(int start, int end){
    vector<TreeNode*> *ans = new vector<TreeNode*>();
    if(start > end)
        ans->push_back(NULL);
    else{
        for(int i = start; i <= end; i++){
            vector<TreeNode*> *leftAll = DFS(start, i-1);
            vector<TreeNode*> *rightAll = DFS(i+1, end);
            for(int j = 0; j < rightAll->size(); j++){
                for(int k = 0; k < leftAll->size(); k++){
                    TreeNode* nn = new TreeNode(i);
                    nn->left = (*leftAll)[k];
                    nn->right = (*rightAll)[j];
                    ans->push_back(nn);
                }
            }
        }
    }
    return ans;
}