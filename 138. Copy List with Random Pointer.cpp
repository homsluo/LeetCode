//
// Created by homsl on 2020/3/25.
//
Node* copyRandomList(Node* head) {
    if(!head)
        return nullptr;

    unordered_map<Node*, Node*> Nodes;
    Node* curr = head;
    Node dummy(0);
    Node* clone = &dummy;

    while(curr){
        if(!Nodes.count(curr))
            Nodes[curr] = new Node(curr->val);
        clone->next = Nodes[curr];
        clone = clone->next;
        if(curr->random){
            if(!Nodes.count(curr->random))
                Nodes[curr->random] = new Node(curr->random->val);
            clone->random = Nodes[curr->random];
        }
        curr = curr->next;
    }
    return dummy.next;
}
