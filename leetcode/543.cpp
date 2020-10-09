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
    int longest_path = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        build_height(root);

        return longest_path;
    }

    int build_height(TreeNode* cur) {
        if (cur == nullptr) return -1;
        int left = build_height(cur->left), right = build_height(cur->right);

        longest_path = max(longest_path, left + right + 2);
        //   cout << cur -> val << ' > ' << keep << ' ' << longest_path << '\n';
        return (max(left, right) + 1);
    }
}
