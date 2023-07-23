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

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class TreeOperations
{
public:
    Node *insert(Node *root, int d)
    {
    }
    Node *delete(Node *node)
    {
    }
    Node *update(Node *node, int d)
    {
    }
};

//---------------------------------Tree DFS traversals
void inorder(TreeNode *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}
void preorder(TreeNode *node)
{
    if (node == NULL)
        return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}
void postorder(TreeNode *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

//----------------------------------Max height of a binary tree
int getHeight(TreeNode *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

// checks 2 Binary trees for structural equality
bool isIdentical(TreeNode *node1, TreeNode *node2)
{
    if (node1 == NULL && node2 == NULL)
        return true;
    if (node1 == NULL || node2 == NULL)
        return false;
    return node1->data == node2->data && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
}
// O(n), O(n)-recursive stack

//-------------------------------------------------------------------Diameter
// finds the diameter D of a binary tree T - no. of nodes N on the longest path P between two leaves in T
// lh+rh+1 : longest path from one leaf node to another leaf node
int getDiameter(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int lh, rh, ld, rd;
    lh = getHeight(node->left);
    rh = getHeight(node->right);
    ld = getDiameter(node->left);
    rd = getDiameter(node->right);
    return max(lh + rh + 1, max(ld, rd));
}
// O(n2)

int getHeightandUpdateDiameter(TreeNode *node, int &d)
{
    if (node == NULL)
        return 0;
    int lh = getHeightandUpdateDiameter(node->left, d);
    int rh = getHeightandUpdateDiameter(node->right, d);
    d = max(d, lh + rh);
    return 1 + max(lh, rh);
}
void diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    getHeightandUpdateDiameter(root, diameter);
    cout << diameter;
}
// O(n)

// sum of all nodes of binary tree
int treeSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);
    return (root->val + leftSum + rightSum;
}

vector<vector<int>> zigzagLevelOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> curLevel, nextLevel;
    int l2r = 1;
    curLevel.push(root);
    while (!curLevel.empty())
    {
        int length = curLevel.size();
        vector<int> level;
        for (int i = 0; i < length; i++)
        {
            TreeNode *node = curLevel.top();
            curLevel.pop();
            level.push_back(node->val);
            if (l2r)
            {
                if (node->left != NULL)
                    nextLevel.push(node->left);
                if (node->right != NULL)
                    nextLevel.push(node->right);
            }
            else
            {
                if (node->right != NULL)
                    nextLevel.push(node->right);
                if (node->left != NULL)
                    nextLevel.push(node->left);
            }
        }
        if (curLevel.empty())
        {
            l2r = 1 - l2r;
            swap(curLevel, nextLevel);
        }
        ans.push_back(level);
    }
    return ans;
}
void dfs(TreeNode *node)
{
    if (node == NULL)
        return;
    TreeNode *temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    dfs(node->left);
    dfs(node->right);
}
TreeNode *invertTree(TreeNode *root)
{
    dfs(root);
    return root;
}
/*
 * Analysis
 * TC - O(n)
 * ASC - O(h) : h is the height of tree ~ logn
 */

int main()
{
    freopen("C:/Users/91626/Documents/IO/in.txt", "r", stdin);
    freopen("C:/Users/91626/Documents/IO/out.txt", "w", stdout);

    TreeOperations myTree;
    Node *root = NULL;

    int t, data;
    cin >> t;
    while (t--)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
}