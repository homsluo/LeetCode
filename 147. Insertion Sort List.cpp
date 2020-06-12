//
// Created by homsl on 2020/3/30.
//
ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* insertNode;

    while(cur){
        insertNode = dummy;
        while(insertNode->next != cur && cur){
            if(insertNode->next->val > cur->val){
                pre->next = cur->next;
                cur->next = insertNode->next;
                insertNode->next = cur;
                cur = pre->next;
                insertNode = dummy;
            }
            else
                insertNode = insertNode->next;
        }
        pre = cur;
        if(cur)
            cur = cur->next;
    }
    return dummy->next;
}
