//
// Created by homsl on 2020/2/25.
//
TreeNode* sortedListToBST(ListNode* head) {
    if(!head)
        return nullptr;

    return helper(head, nullptr);
}

TreeNode* helper(ListNode* start, ListNode* end){
    if(start == end)
        return nullptr;
    ListNode* slow = start;
    ListNode* fast = start;
    while(fast != end && fast->next != end){
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = helper(start, slow);
    root->right = helper(slow->next, end);
    return root;
}
