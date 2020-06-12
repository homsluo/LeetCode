//
// Created by homsl on 2020/5/13.
//
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* newhead = new ListNode(0);
    ListNode* cur = head;
    ListNode* temp;
    while(cur){
        temp = cur->next;
        cur->next = newhead->next;
        newhead->next = cur;
        cur = temp;
    }
    return newhead->next;
}

// Recursion

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
