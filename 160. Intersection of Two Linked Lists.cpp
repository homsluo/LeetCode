//
// Created by homsl on 2020/4/9.
//
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB)
        return nullptr;
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    int flagp1 = 0;
    int flagp2 = 1;
    while(p1 != p2){
        if(!p1->next && !p2->next)
            return nullptr;
        if(!p1->next){
            if(flagp1)
                p1 = headA;
            else
                p1 = headB;
            flagp1 = !flagp1;
        }
        else
            p1 = p1->next;
        if(!p2->next){
            if(flagp2)
                p2 = headA;
            else
                p2 = headB;
            flagp2 = !flagp2;
        }
        else
            p2 = p2->next;
    }
    return p1;
}
