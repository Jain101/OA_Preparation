#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Trees_Solution
{
public:
    /*
     * Date : 19.07.2023
     * Problem : https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
     * Approach : do preorder traversal and count good nodes(having value>=lat_max)
     */
    int dfs(TreeNode *node, int mx, int res)
    {
        if (node == NULL)
            return 0;
        res = (node->val) >= mx ? 1 : 0;
        mx = max(mx, node->val);
        res += dfs(node->left, mx, res) + dfs(node->right, mx, res);
        return res;
    }
    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        int maxval = root->val;
        return dfs(root, maxval, ans);
    }
    /*
     * Analysis
     * TC - O(n)
     * ASC - O(h) : h is the height of tree ~ logn
     */
};