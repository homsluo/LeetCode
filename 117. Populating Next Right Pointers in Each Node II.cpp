//
// Created by homsl on 2020/3/2.
//
Node* connect(Node* root) {
    if(!root || (!root->left && !root->right))
        return root;
    Node* curr = root;
    Node* dummy = new Node(0);
    Node* prev = dummy;
    while(curr){
        while(curr){
            if(curr->left){
                if(dummy->next == NULL)
                    dummy->next = curr->left;
                prev->next = curr->left;
                prev = prev->next;
            }
            if(curr->right){
                if(dummy->next == NULL)
                    dummy->next = curr->right;
                prev->next = curr->right;
                prev = prev->next;
            }
            curr = curr->next;
        }
        curr = dummy->next;
        dummy->next = NULL;
        prev = dummy;
    }
    return root;
}
