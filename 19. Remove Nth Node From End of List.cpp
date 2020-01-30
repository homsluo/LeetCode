//
// Created by homsl on 2019/11/26.
//

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp1 = head;
    ListNode* temp2 = head;
    int count = 0;
    while(temp1->next != NULL){
        temp1 = temp1->next;
        count ++;
        if(count > n)
            temp2 = temp2->next;
    }
    if(count < n){      // the node to be removed is head
        head = head->next;
        return head;
    }
    temp2->next = temp2->next->next;
    return head;
}