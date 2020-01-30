//
// Created by homsl on 2020/1/29.
//
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || head->next == nullptr)
        return head;
    int len = 0;
    ListNode* cur = head;
    while(cur->next != nullptr){
        len++;
        cur = cur->next;
    }
    len++;
    int jump = k % len;
    ListNode* slow = head;
    ListNode* fast = head;
    while(jump > 0){
        fast = fast->next;
        jump--;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = nullptr;
    return head;
}
