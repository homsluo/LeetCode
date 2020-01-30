//
// Created by homsl on 2019/12/27.
//

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while(l1 && l2){
        if(l1->val >= l2->val){
            cur->next = l2;
            l2 = l2->next;
        }
        else{
            cur->next = l1;
            l1 = l1->next;
        }
        cur = cur->next;
    }
    if(l1) cur->next = l1;
    if(l2) cur->next = l2;

    return dummy->next;
}

// Recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};