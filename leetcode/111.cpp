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
    int ans = INT_MAX;
    int minDepth(TreeNode* root) {
        dfs (root, 0);
        
        return ans == INT_MAX ? 0 : ans;
    }
    bool dfs (TreeNode *cur, int depth) {
        if (cur == nullptr) {
            return false;
        }
        cout << cur -> val << '\n';
        bool left = dfs (cur -> left, depth+1);
        bool right = dfs (cur -> right, depth+1);
        if ( ! (left || right) ) {
            ans = min (ans, depth+1);
        }
        return true;
    }
};
