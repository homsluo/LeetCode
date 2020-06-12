//
// Created by homsl on 2020/5/29.
//
void deleteNode(ListNode* node) {
    int v = node->next->val;
    ListNode* next = node->next->next;
    node->next = next;
    node->val = v;
}
