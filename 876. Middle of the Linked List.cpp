//
// Created by homsl on 2020/4/9.
//

ListNode* middleNode(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}