/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> ans;
    map<int, bool> occurred;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        buildans(root, 0);

        reverse(ans.begin(), ans.end());

        return ans;
    }

    void buildans(TreeNode* cur, int level) {
        if (cur == nullptr) return;

        if (occurred.count(level) == 0) {
            occurred[level] = true;
            vector<int> keep(1, cur->val);
            ans.emplace_back(keep);
        } else {
            ans[level].emplace_back(cur->val);
        }

        buildans(cur->left, level + 1);
        buildans(cur->right, level + 1);
    }
};
