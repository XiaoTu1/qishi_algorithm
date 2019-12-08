class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        stack<Node*> S;
        unordered_map<Node*, Node*> hash;
        S.push(node);
        hash[node] = new Node(node->val, vector<Node*>());
        
        while (!S.empty()) {
            Node* top = S.top();
            S.pop();
            for (Node* n: top->neighbors) {
                if (hash.find(n) == hash.end()) {
                    hash[n] = new Node(n->val, vector<Node*>());
                    S.push(n);
                }
                hash[top]->neighbors.push_back(hash[n]);
            }
        }
        
        return hash[node];
    }
};
