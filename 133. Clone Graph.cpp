//
// Created by homsl on 2020/3/22.
//
Node* cloneGraph(Node* node) {
    if(!node)
        return nullptr;

    unordered_map<int, Node*> clone;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        // Copy node
        if(!clone.count(temp->val)){
            clone[temp->val] = new Node(temp->val);
        }
        Node* curr = clone[temp->val];
        for(Node* p:temp->neighbors){
            if(!clone.count(p->val))    //If copy exist, the node is read already
                q.push(p);
            if(!clone.count(p->val)){
                clone[p->val] = new Node(p->val);
            }
            curr->neighbors.push_back(clone[p->val]);
        }
    }

    return clone[1];
}
