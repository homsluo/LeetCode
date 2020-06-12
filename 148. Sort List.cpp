//
// Created by homsl on 2020/3/30.
//
ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
}

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(l1 && l2){
        if(l1->val > l2->val)
            swap(l1, l2);
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
    }
    if(l1)
        tail->next = l1;
    if(l2)
        tail->next = l2;
    return dummy.next;
}
//-----------------------------------------------------------
//Bottom Up
ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
        return head;

    int size = 1;
    ListNode* cur = head->next;
    while(cur){
        size++;
        cur = cur->next;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* l;
    ListNode* r;
    ListNode* tail;
    for(int len = 1; len <= size; len<<=1){
        cur = dummy.next;
        tail = &dummy;
        while(cur){
            l = cur;
            r = split(l, len);
            cur = split(r, len);
            auto merged = merge(l, r);
            tail->next = merged.first;
            tail = merged.second;
        }
    }

    return dummy.next;
}

ListNode* split(ListNode* head, int len){
    while(--len && head){
        head = head->next;
    }
    ListNode* res = head?head->next:nullptr;
    if(head)
        head->next = nullptr;
    return res;
}
pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(l1 && l2){
        if(l1->val > l2->val)
            swap(l1, l2);
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
    }
    tail->next = l1?l1:l2;
    while(tail->next)
        tail = tail->next;
    return {dummy.next, tail};
}