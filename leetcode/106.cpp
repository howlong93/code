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
    TreeNode* root = nullptr;
    vector<int> in, pre, ininpre, preinin;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        pre = preorder;
        in = inorder;

        ininpre.resize(preorder.size());
        preinin.resize(preorder.size());
        for (size_t i = 0; i < preorder.size(); i++)
            for (size_t j = 0; j < preorder.size(); j++)
                if (preorder[i] == inorder[j]) {
                    preinin[i] = j;
                    ininpre[j] = i;
                }

        build_tree(root, 0, preorder.size() - 1);
        return root;
    }
    void build_tree(TreeNode*& cur, int left, int right) {
        if (left > right) return;

        cur = new (TreeNode);

        int keep = -1;
        for (size_t i = left; i <= right; i++) keep = max(ininpre[i], keep);

        cur->val = pre[keep];

        build_tree(cur->left, left, preinin[keep] - 1);
        build_tree(cur->right, preinin[keep] + 1, right);
    }
};
