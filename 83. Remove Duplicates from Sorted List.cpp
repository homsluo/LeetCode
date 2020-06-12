//
// Created by homsl on 2020/2/6.
//
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || head->next == nullptr)
        return head;
    ListNode* cur = head->next;
    ListNode* pre = head;
    while(cur){
        if(pre->val == cur->val){
            cur = cur->next;
            pre->next = cur;
        }
        else{
            pre = pre->next;
            cur = cur->next;
        }
    }
    return head;
}
