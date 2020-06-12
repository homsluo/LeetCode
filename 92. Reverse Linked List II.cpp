//
// Created by homsl on 2020/2/13.
//
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head || head->next == nullptr || m == n)
        return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* mNode = head;
    ListNode* preM = &dummy;
    ListNode* nNode;
    int cur = 1;
    for(; cur < m; cur++){
        preM = mNode;
        mNode = mNode->next;
    }
    nNode = mNode;
    for(; cur < n; cur++){
        nNode = nNode->next;
    }
    while(mNode != nNode){
        preM->next = mNode->next;
        mNode->next = nNode->next;
        nNode->next = mNode;
        mNode = preM->next;
    }
    return dummy.next;
}
