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
    vector<int> list;
    int keep = 0;
    TreeNode *head;
    int sumRootToLeaf(TreeNode *root) {
        head = root;
        gothrough(root);

        return keep;
    }

    int calcnum(vector<int> str) {
        int times = 1, ans = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            ans += str[i] * times;
            times *= 2;
        }
        cout << ans << ' ';
        return ans;
    }

    void gothrough(TreeNode *cur) {
        list.emplace_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            keep += calcnum(list);
            list.pop_back();
            return;
        }

        if (cur->left != nullptr) gothrough(cur->left);
        if (cur->right != nullptr) gothrough(cur->right);

        list.pop_back();
    }
};
