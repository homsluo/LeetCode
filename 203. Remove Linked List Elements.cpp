//
// Created by homsl on 2020/5/12.
//
ListNode* removeElements(ListNode* head, int val) {
    if(!head)
        return nullptr;
    ListNode dummy(0);
    ListNode* pre = &dummy;
    pre->next = head;
    ListNode* cur = head;
    while(cur){
        if(cur->val == val){
            pre->next = cur->next;
            cur = pre->next;
        }
        else{
            pre = pre->next;
            cur = cur->next;
        }
    }
    return dummy.next;
}
