//
// Created by homsl on 2020/6/12.
//
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    int carry = 0;
    while(l1 && l2){
        int cur = l1->val+l2->val+carry;
        carry = cur/10;
        tail->next = new ListNode(cur%10);
        tail = tail->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    l1 = l1?l1:l2;
    while(l1){
        int cur = l1->val+carry;
        carry = cur/10;
        tail->next = new ListNode(cur%10);
        tail = tail->next;
        l1 = l1->next;
    }
    if(carry)
        tail->next = new ListNode(carry);
    return dummy->next;
}
