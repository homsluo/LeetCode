//
// Created by homsl on 2020/2/6.
//
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || head->next == nullptr)
        return head;
    ListNode* dummy = new ListNode(0);
    ListNode* pre = dummy;
    ListNode* cur = head;
    ListNode* rnode = dummy;
    while(cur){
        if((pre == dummy || pre->val != cur->val) && (cur->next == nullptr || cur->val != cur->next->val)){
            rnode->next = cur;
            rnode = rnode->next;
        }
        pre = cur;
        cur = cur->next;
        pre->next = nullptr;
    }
    return dummy->next;
}
