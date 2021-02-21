/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> cpy;
    Node* cloneGraph(Node* node) {
        cpy = vector<Node *> (101, nullptr);
        if (node != nullptr) cpy[1] = dfs (node);
        return cpy[1];
    }
    Node* dfs (Node *cur) {
        cout << cur -> val << '\n';
        if (cpy[cur -> val] == nullptr) cpy[cur -> val] = new Node (cur -> val);
        
        for (auto k: cur -> neighbors) {
            if (cpy[k -> val] == nullptr) cpy[k -> val] = dfs (k);
            cpy[cur -> val] -> neighbors.emplace_back(cpy[k -> val]);
        }
        return cpy[cur -> val];
    }
};
