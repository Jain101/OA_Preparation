#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
const int lg = 14;
vector<int> children[MAX_N];
int up[MAX_N][lg];
int depth[MAX_N];

void dfs(int a)
{
    for (int &b : children[a])
    {
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for (int j = 1; j < lg; j++)
            up[b][j] = up[up[b][j - 1]][j - 1];
        dfs(b);
    }
}

// O(n)
int lca0(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    while (depth[a] > depth[b])
    {
        a = up[a][0];
    }
    while (a != b)
    {
        a = up[a][0];
        b = up[b][0];
    }
    return a;
}
// O(log(n))
int lca1(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    for (int i = lg - 1; i >= 0; i--)
        if (k & (1 << i))
            a = up[a][i];
    if (a == b)
        return a;
    for (int i = lg - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/91626/Documents/IO/in.txt", "r", stdin);
    freopen("C:/Users/91626/Documents/IO/out.txt", "w", stdout);
#endif
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int c;
            cin >> c;
            children[i].push_back(c);
        }
    }
    dfs(0);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca1(u, v) << '\n';
    }

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}