//
// Created by homsl on 2020/1/6.
//

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    ListNode* cur = head;

    while(cur){
        ListNode* p = cur;
        for(int i = k; i > 0; i--,p = p->next){
            if(!p){
                tail->next = cur;
                return dummy.next;
            }
        }
        tail->next = reverse(cur, k);
        for(; tail->next != nullptr; tail = tail->next);
        cur = p;
    }
    return dummy.next;
}

ListNode* reverse(ListNode* head, int k){
    ListNode* res = nullptr;
    ListNode* node;

    while(k){
        node = head;
        head = head->next;
        node->next = res;
        res = node;
        k--;
    }

    return res;
}
//