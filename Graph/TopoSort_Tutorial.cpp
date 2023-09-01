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
#define printV(v, a)       \
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
    ans.push(i);
}
void toposort_DFS()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    memset(vis, false, sizeof vis);
    REP(i, 1, n, 1)
    {
        if (!vis[i])
            dfs(i);
    }
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
}

void toposort_BFS()
{
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
    }

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}