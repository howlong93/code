/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
   public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node *> q;
        vector<vector<int>> ans;
        Node *cur = root;

        q.emplace(root);
        while (q.size()) {
            vector<int> line;
            int sizeofq = q.size();
            for (int i = 0; i < sizeofq; i++) {
                cur = q.front();
                q.pop();
                if (cur != nullptr) {
                    line.emplace_back(cur->val);
                    for (auto k : cur->children) q.emplace(k);
                }
            }
            if (line.size() > 0) ans.emplace_back(line);
        }

        return ans;
    }
};
