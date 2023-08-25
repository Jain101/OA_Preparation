#include <bits/stdc++.h>
using namespace std;
#define int long long
const int K = 14, MAX_N = 200001;
/**
 * Date : 07.08.2023
 * Problem 1
 * Approach : use prefix sums, why not segment tree,fenwick/BIT? coz it is static and there are no updates, so use static methods
 * TC : O(q) for all queries, O(1) per query process = O(q)
 */
void StaticRangeSumQueries1() // prefix sum approach
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    vector<long long> ps(n + 1);
    ps[1] = x[1];
    for (int i = 2; i <= n; i++)
        ps[i] = ps[i - 1] + x[i];
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << '\n';
    }
}
void StaticRangeSumQueries2() // sparsh table approach
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    // preprocessing sparse table - O(n*logn)
    vector<vector<long long>> sp(lg[n] + 1, vector<long long>(n));
    for (int i = 0; i < n; i++)
        sp[0][i] = x[i];
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            sp[i][j] = sp[i - 1][j] + sp[i - 1][j + (1 << (i - 1))];
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        long long sum = 0;
        // iterate through lg[i]
        for (int i = lg[n]; i >= 0; i--)
        {
            if ((1 << i) <= (r - l + 1))
            {
                sum += sp[i][l];
                l += (1 << i);
            }
        }
        cout << sum << '\n';
    }
}
// sp[i][j] - start from j and take len=2^i subarray
void StaticRangeMinQueries()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    // preprocessing log - process it for everytime...gonna be same everywhere - O(n)
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    // preprocessing sparse table - O(n*logn)
    vector<vector<int>> sp(lg[n] + 1, vector<int>(n));
    for (int i = 0; i < n; i++)
        sp[0][i] = x[i];
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int i = lg[r - l + 1];
        cout << min(sp[i][l], sp[i][r - (1 << i) + 1]) << '\n';
    }
}

/**
 * Date : 11.08.2023
 * Problem 7
 * Approach : use 2D prefix sums, why not segment tree,fenwick/BIT? coz it is static and there are no updates, so use static methods
 * TC : O(NQ)[usaco] but it should be O(N^2 + Q)
 */
void ForestQueries()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree_sum(n + 1, vector<int>(n + 1)); // 2D prefix sum array
    // taking input & preprocessing
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            tree_sum[i][j] = tree_sum[i - 1][j] + tree_sum[i][j - 1] - tree_sum[i - 1][j - 1] + (ch == '*');
        }
    }
    // query processing
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = tree_sum[x2][y2] - tree_sum[x1 - 1][y2] - tree_sum[x2][y1 - 1] + tree_sum[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/91626/Documents/IO/in.txt", "r", stdin);
    freopen("C:/Users/91626/Documents/IO/out.txt", "w", stdout);
#endif
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ForestQueries();

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}