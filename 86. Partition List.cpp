//
// Created by homsl on 2020/2/10.
//
ListNode* partition(ListNode* head, int x) {
    if(!head)
        return head;
    ListNode Lard(0);
    ListNode Lesd(0);
    ListNode* Lar = &Lard;
    ListNode* Les = &Lesd;
    ListNode* cur = head;
    while(cur){
        if(cur->val < x){
            Les->next = cur;
            Les = Les->next;
        }
        else{
            Lar->next = cur;
            Lar = Lar->next;
        }
        cur = cur->next;
    }
    Les->next = Lard.next;
    Lar->next = nullptr;
    return Lesd.next;
}
