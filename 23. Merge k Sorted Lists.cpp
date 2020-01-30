//
// Created by homsl on 2019/12/30.
//

// Priority Queue
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    auto comp = [](ListNode* a, ListNode* b){return a->val > b->val;};
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);

    for(ListNode* temp : lists){
        if(temp)
            q.push(temp);
    }

    while(!q.empty()){
        cur->next = q.top();
        cur = cur->next;
        if(cur->next)
            q.push(cur->next);
        q.pop();
    }

    return dummy->next;
}

// Reuse of LC.21, mergesort

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0, lists.size()-1);
}

ListNode* merge(vector<ListNode*>& lists, int l, int r){
    if(l > r) return nullptr;
    if(l == r) return lists[l];
    if(l+1 == r) return merge2list(lists[l], lists[r]);
    int m = l + (r-l)/2;
    ListNode* l1 = merge(lists, l, m);
    ListNode* l2 = merge(lists, m+1, r);
    return merge2list(l1, l2);
}

ListNode* merge2list(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while(l1 && l2){
        if(l1->val > l2->val){
            tail->next = l2;
            l2 = l2->next;
        }
        else{
            tail->next = l1;
            l1 = l1->next;
        }
        tail = tail->next;
    }
    tail->next = l1? l1: l2;
    return dummy.next;
}