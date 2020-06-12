//
// Created by homsl on 2020/3/26.
//
bool hasCycle(ListNode *head) {
    if(!head || !head->next)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;
    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}
