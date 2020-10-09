/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue <TreeNode *> q;
        TreeNode *cur = root;
        
        q.push(cur);
        while (q.size() > 0) {
            vector<int> line;
            int sizeofq = q.size();
            for (int i = 0; i < sizeofq; i++) {
                cur = q.front();
                q.pop();
                if (cur != nullptr) {
                    line.emplace_back(cur -> val);
                    if (cur -> left != nullptr) q.emplace (cur -> left);
                    if (cur -> right != nullptr) q.emplace (cur -> right);
                }
            }
            if (line.size() > 0) ans.emplace_back(line);
        }
        
        for (size_t i = 0; i < ans.size(); i++)
            if (i % 2) reverse (ans[i].begin(), ans[i].end());
        
        return ans;
    }
};
