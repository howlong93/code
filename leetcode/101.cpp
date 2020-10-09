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
    bool isSymmetric(TreeNode *root) {
        bool flag = true;
        vector<int> left, right;
        if (root != nullptr) {
            build_left(root->left, left);
            build_right(root->right, right);
        }

        if (left == right) return true;
        return false;
    }
    void build_left(TreeNode *cur, vector<int> &left) {
        if (cur == nullptr) {
            left.emplace_back(-1);
            return;
        }

        left.emplace_back(cur->val);
        build_left(cur->right, left);
        build_left(cur->left, left);
    }
    void build_right(TreeNode *cur, vector<int> &right) {
        if (cur == nullptr) {
            right.emplace_back(-1);
            return;
        }
        right.emplace_back(cur->val);
        build_right(cur->left, right);
        build_right(cur->right, right);
    }
};
