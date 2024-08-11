// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<int, int> d, fat;

    void dfs(TreeNode *node) {
        if (node->left) {
            d[node->left->val] = 1 + d[node->val];
            fat[node->left->val] = node->val;
            dfs(node->left);
        }

        if (node->right) {
            d[node->right->val] = 1 + d[node->val];
            fat[node->right->val] = node->val;
            dfs(node->right);
        }
    }

    void trav(TreeNode *node, int target, TreeNode *ans) {
        if (node->val == target) {
            *ans = *node;
            return;
        }

        if (node->left) trav(node->left, target, ans);
        if (node->right) trav(node->right, target, ans);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        d[root->val] = 0;
        fat[root->val] = -1;
        dfs(root);

        int u = p->val, v = q->val;
        if (d[u] > d[v]) {
            swap(u, v);
        }

        while (d[u] < d[v]) {
            v = fat[v];
        }

        while (u != v) {
            v = fat[v];
            u = fat[u];
        }

        TreeNode *ans = new TreeNode();
        trav(root, u, ans);
        return ans;
    }
};
