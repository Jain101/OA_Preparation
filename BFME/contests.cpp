#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define INF64 1e18
#define MOD 1000000007
#define PI 3.1415926536
#define ll long long
#define ld long double
#define xx first
#define yy second
#define mp make_pair
#define pb push_backṇ
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define REP(i, a, b, t) for (int i = a; i <= b; i += t)
#define REPr(i, a, b, t) for (int i = a; i >= b; i -= t)

#define inputV(v)     \
    for (auto &i : v) \
    cin >> i
#define inputV2(v)        \
    for (auto &i : v)     \
    {                     \
        for (auto &j : i) \
        {                 \
            cin >> j;     \
        }                 \
    }
#define printV(v)    \
    for (auto i : v) \
        cout << i << " ";
#define printV2(v)            \
    for (auto i : v)          \
    {                         \
        for (auto j : i)      \
        {                     \
            cout << j << " "; \
        }                     \
        cout << "\n";         \
    }
#define all(v) v.begin(), v.end()

#define check(pred) (pred ? "YES\n" : "NO\n")
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

/*@Contest 6: Graphs*/
/*
 * Date : 20.07.2023
 * Problem C : https://codedrills.io/contests/bfme-2023-contest-6-graphs/problems/island-count
 * Approach : a simple flood-fill approach problem but keep an eye on the edge cases
 */
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
vector<string> grid;
vector<vector<bool>> visited;
int n, m;
bool isValid(int a, int b)
{
    return (a < n && a >= 0 && b < m && b >= 0);
}
void dfs(int r, int c)
{
    if (!isValid(r, c) || grid[r][c] == '0' || visited[r][c])
        return;
    visited[r][c] = true;
    REP(i, 0, 7, 1)
    dfs(r + dx[i], c + dy[i]);
}
int getCount()
{
    int count = 0;
    n = grid.size();
    if (n == 0)
        return 0;
    m = grid[0].length();
    visited.assign(n, vector<bool>(m, false));
    REP(i, 0, n - 1, 1)
    {
        REP(j, 0, m - 1, 1)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                count++;
                dfs(i, j);
            }
        }
    }
    return count;
}
/*
 * Analysis
 * TC - O(mn+8mn) ~ O(mn)
 * SC - O(mn)
 */

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/91626/Documents/IO/in.txt", "r", stdin);
    freopen("C:/Users/91626/Documents/IO/out.txt", "w", stdout);
#endif
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
    }

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}