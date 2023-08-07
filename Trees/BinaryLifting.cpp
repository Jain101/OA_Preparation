#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1000000000

/**                 BINARY LIFTING
 * we will jump up in powers of 2, coz every numbers can be represented as sum of powers of 2
 * ASSUMPTIONS:
 * 1.
 *
 * int up[N][LOG] - N:number of nodes, LOG:log(height of tree)
 * up[v][j] - 2^j th ancestor of v
 * PSEUODOCODE:
 * --------------If Nodes are in order[parent[v]<v]
 * for v->[0,N-1]:
 *  up[v][0]=parent[v]
 *  for j->[1,LOG-1]:
 *     up[v][j] = up[up[v][j-1]][j-1]
 * --------------If Nodes are not in order[parent[v]>v]
 * for v->[0,N-1]:
 *  up[v][0]=parent[v]
 *  for j->[1,LOG-1]:
 *      for v->[0,N-1]:
 *          up[v][j] = up[up[v][j-1]][j-1]
 * COMPLEXITY:ANALYSIS:
 * TC : O(n*log(n))
 * SC : O(n*log(n))
 * WHEN:TO:USE:
 * When tree is not balanced, if it is balanced then DFS will work faster too, IDK much
 */
/**
 * Date : 06.08.2023
 * Problem Link : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
 * Technique Used : Binary Lifting
 * TC : O(n*log(n))
 * SC : O(n*log(n))
 */
class TreeAncestor
{
    vector<vector<int>> up;
    int lg;
    vector<int> depth;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        lg = 1;
        while ((1 << lg) <= n)
            lg++;
        up = vector<vector<int>>(n, vector<int>(lg));
        depth = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            up[i][0] = parent[i];
            depth[i] = depth[parent[i]] + 1;
            for (int j = 1; j < lg; j++)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < lg; i++)
        {
            if (k & (1 << i))
                node = up[node][i];
        }
        return node;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/91626/Documents/IO/in.txt", "r", stdin);
    freopen("C:/Users/91626/Documents/IO/out.txt", "w", stdout);
#endif
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, node;
    vector<int> parent;
    TreeAncestor *obj = new TreeAncestor(n, parent);
    int ans = obj->getKthAncestor(node, k);
    cout << ans;

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}