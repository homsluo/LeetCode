//
// Created by homsl on 2020/5/29.
//
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    int odd = fast?1:0;   // see if the length is odd
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur != slow){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    if(odd)
        slow = slow->next;
    while(slow){
        if(slow->val != pre->val)
            return false;
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}
