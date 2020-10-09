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
    set<int> savinglevel;
    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(TreeNode* root) {
        build(root, 0);

        return ans;
    }

    void build(TreeNode* cur, int level) {
        if (cur == nullptr) return;

        if (savinglevel.find(level) == savinglevel.end()) {
            savinglevel.emplace(level);
            vector<int> keep;
            keep.emplace_back(cur->val);
            ans.emplace_back(keep);
        } else {
            ans[level].emplace_back(cur->val);
        }

        build(cur->left, level + 1);
        build(cur->right, level + 1);
    }
};
