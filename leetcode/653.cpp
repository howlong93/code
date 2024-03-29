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
    unordered_map<int, int> cnt;
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        cnt[root -> val] = 1;
        if (root->val != k-root->val && cnt[k-root->val] == 1) return true;
        return (findTarget(root -> left, k) | findTarget(root -> right, k));
    }
};
