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

const long long INF = 1e18;

class Solution {
public:
    bool helper(TreeNode *root, long long mn, long long mx) {
        if (!root) {
            return true;
        }

        if (!(root->val > mn && root->val < mx)) {
            return false;
        }

        bool ans = true;
        ans &= helper(root->left, mn, root->val);
        ans &= helper(root->right, root->val, mx);

        return ans;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, -INF, INF);
    }
};
