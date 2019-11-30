/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        queue<Node*> Q;
        unordered_map<Node*, Node*> clone;
        Q.push(node);
        clone[node] = new Node(node->val, vector<Node*>());
        
        while (!Q.empty()) {
            Node* head = Q.front();
            Q.pop();
            for (auto n: head->neighbors) {
                if (clone.find(n) == clone.end()) {
                    clone[n] = new Node(n->val, vector<Node*>());
                    Q.push(n);
                }
                clone[head]->neighbors.push_back(clone[n]);
            }
        }
        
        return clone[node];
    }
};
