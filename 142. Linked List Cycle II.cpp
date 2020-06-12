//
// Created by homsl on 2020/3/26.
//
ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next)
        return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(head != fast){
                head = head->next;
                fast = fast->next;
            }
            return head;
        }
    }
    return nullptr;
}
