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

vector<int> ans = {};

void getelement(TreeNode* cur) {
    if (cur == nullptr) return;
    ans.emplace_back(cur->val);
    getelement(cur->left);
    getelement(cur->right);
}

class Solution {
   public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        ans = {};
        getelement(root1);
        getelement(root2);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
