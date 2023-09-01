#include <bits/stdc++.h>
using namespace std;

#define int long long // TLE or MLE remove
#define INF 1e9
#define INF64 1e18
#define MOD 1e9 + 7
#define PI 3.1415926536
#define ll long long
#define ld long double
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>
#define REP(i, a, b, t) for (int i = a; i <= b; i += t)
#define REPr(i, a, b, t) for (int i = a; i >= b; i -= t)

#define TC     \
    int tt;    \
    cin >> tt; \
    while (tt--)

#define inputV(v, a)       \
    REP(i, a, v.size(), 1) \
    {                      \
        cin >> v[i];       \
    }
#define inputV2(v, a)          \
    REP(i, a, v.size(), 1)     \
    {                          \
        REP(j, a, v.size(), 1) \
        {                      \
            cin >> v[i][j];    \
        }                      \
    }
#define printV1(v, a)      \
    REP(i, a, v.size(), 1) \
    cout << v[i] << " ";
#define printV2(v, a)               \
    REP(i, a, v.size(), 1)          \
    {                               \
        REP(j, a, v.size(), 1)      \
        {                           \
            cout << v[i][j] << " "; \
        }                           \
        cout << "\n";               \
    }
#define all(v) v.begin(), v.end()

#define check(pred) (pred ? "YES\n" : "NO\n")
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vi adj[10001];
stack<int> ans;
bool vis[10001];
int n, m;
void dfs(int i)
{
    vis[i] = true;
    for (int &u : adj[i])
    {
        if (!vis[u])
            dfs(u);
    }
    // pushing the nodes after all dfs calls are done(stack full? now take out top and put it in ans)
    ans.push(i);
}
void toposort_DFS()
{
    // initialization
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    memset(vis, false, sizeof vis);
    // doing dfs on all nodes(!vis)
    REP(i, 1, n, 1)
    {
        if (!vis[i])
            dfs(i);
    }
    // printing stack
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
}
/**
 * Date : 01.09.2023
 * Problem : https://www.spoj.com/problems/TOPOSORT/
 */
vi adj[10001];
int out_deg[10001];
int in_deg[10001];
bool vis[10001];
vi ts;
int n, m;
void toposort_bfs()
{
    // initialization
    cin >> n >> m;
    memset(out_deg, 0, sizeof out_deg);
    memset(in_deg, 0, sizeof in_deg);
    memset(vis, false, sizeof vis);
    ts.clear();
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        out_deg[a]++;
        in_deg[b]++;
    }
    // bfs
    // min heap to get lexicographically smallest node all the time to push into ts
    // take all nodes having in_deg=0 and do the operation and discard them,
    // it will affect its neighbours so recalculate in_deg of neighbours, and continue the process
    min_heap<int> pq;
    REP(i, 1, n, 1)
    {
        if (in_deg[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        ts.pb(u);
        for (int &v : adj[u])
        {
            in_deg[v]--;
            if (in_deg[v] == 0)
                pq.push(v);
        }
    }
    if (ts.size() == n)
    {
        printV1(ts, 0);
    }
    else
        cout << "Sandro fails.";
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

    TC
    {
        toposort_bfs();
    }

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}