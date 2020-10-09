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
    vector<bool> check;
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(build_height(root->left) - build_height(root->right)) <= 1)
            check.emplace_back(true);
        else
            check.emplace_back(false);

        bool ans = true;
        for (auto k : check) ans = ans & k;

        return ans;
    }
    int build_height(TreeNode* cur) {
        if (cur == nullptr) return 0;

        int a = build_height(cur->left), b = build_height(cur->right);
        if (abs(a - b) <= 1)
            check.emplace_back(true);
        else
            check.emplace_back(false);
        return (max(a, b) + 1);
    }
};
