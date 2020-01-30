//
// Created by homsl on 2020/1/2.
//

ListNode* swapPairs(ListNode* head) {
    if(!head)
        return nullptr;
    ListNode dummy(0);
    ListNode* tail = &dummy;

    ListNode* q = head->next;
    ListNode* s = head;
    while(q){
        tail->next = q;
        q = q->next;
        tail = tail->next;
        tail->next = s;
        s = q;
        if(q){
            q = q->next;
        }
        tail = tail->next;
    }
    tail->next = s;
    return dummy.next;
}