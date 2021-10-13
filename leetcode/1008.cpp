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
    void insert(TreeNode*& cur, int val) {
        if (cur == nullptr) cur = new TreeNode(val);
        if (cur->val < val) {
            if (cur->right != nullptr)
                insert(cur->right, val);
            else
                cur->right = new TreeNode(val);
        }
        if (cur->val > val) {
            if (cur->left != nullptr)
                insert(cur->left, val);
            else
                cur->left = new TreeNode(val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (auto k : preorder) {
            insert(root, k);
        }
        return root;
    }
};
