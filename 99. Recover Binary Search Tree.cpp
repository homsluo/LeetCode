//
// Created by homsl on 2020/2/18.
//
// Morris Traversal
void recoverTree(TreeNode* root) {
    TreeNode* current = root;
    TreeNode* pre = new TreeNode(INT32_MIN);
    bool firsttime = true;
    TreeNode* first;
    TreeNode* second;
    while(current){
        if(!current->left){
            if(pre->val > current->val && firsttime){
                first = pre;
                firsttime = false;
            }
            if(pre->val > current->val && !firsttime){
                second = current;
            }
            pre = current;
            current = current->right;
        }
        else{
            TreeNode* predecessor = current->left;
            while(predecessor->right != current && predecessor->right){
                predecessor = predecessor->right;
            }
            if(!predecessor->right){
                predecessor->right = current;
                current = current->left;
            }
            else{
                predecessor->right = nullptr;
                if(pre->val > current->val && firsttime){
                    first = pre;
                    firsttime = false;
                }
                if(pre->val > current->val && !firsttime){
                    second = current;
                }
                pre = current;
                current = current->right;
            }
        }
    }
    if(first && second){
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}
