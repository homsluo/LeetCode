//
// Created by homsl on 2020/3/27.
//
void reorderList(ListNode* head) {
    // 1.Find the mid Node of linked list
    // 2.Reverse linked list
    // 3.Construct a new linked list from 2 existed linked list
    if(!head || !head->next || !head->next->next)
        return;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* nhead = slow->next;
    slow->next = nullptr;

    ListNode* cur = nhead->next;
    nhead->next = nullptr;
    ListNode* next;
    while(cur){
        next = cur->next;
        cur->next = nhead;
        nhead = cur;
        cur = next;
    }

    while(head && nhead){
        next = head->next;
        head->next = nhead;
        nhead = nhead->next;
        head->next->next = next;
        head = next;
    }
    return;
}

//------------------------------------------------------------------------
void reorderList(ListNode* head) {
    // 1.Find the mid Node of linked list
    // 2.Reverse linked list
    // 3.Construct a new linked list from 2 existed linked list
    if(!head || !head->next || !head->next->next)
        return;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow;
    ListNode* pre = slow->next;
    while(pre->next){
        ListNode* cur = pre->next;
        pre->next = cur->next;
        cur->next = mid->next;
        mid->next = cur;
    }

    ListNode* p1 = head;
    ListNode* p2 = mid->next;
    while(p1 != mid){
        mid->next = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = mid->next;
    }
    return;
}