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
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vii vector<pii>
#define REP(i, a, b, t) for (int i = a; i <= b; i += t)
#define REPr(i, a, b, t) for (int i = a; i >= b; i -= t)

#define TC     \
    int tt;    \
    cin >> tt; \
    while (tt--)

#define inputV(v, a)           \
    REP(_, a, v.size() - 1, 1) \
    {                          \
        cin >> v[_];           \
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

/**
 * Problem : Sending email-UVa[https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927]
 * Topic : Dijkstra's Algorithm
 * Date : 28.08.2023
 *
 */

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s++;
    t++;
    // adjacency list
    map<int, vii> AL;
    REP(i, 1, m, 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        AL[u].pb({v, w});
        AL[v].pb({u, w});
    }
    // dijkstra's algo using min heap
    vi dist(n + 1, INF);
    dist[s] = 0;
    min_heap<pii> pq;
    pq.push({0, s});
    vi used(n + 1, false);
    while (!pq.empty())
    {
        int u = pq.top().yy;
        pq.pop();
        if (used[u])
            continue;
        used[u] = true;
        for (auto &a : AL[u])
        {
            int v = a.xx;
            int w = a.yy;
            // relaxing tense edge
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[t] != INF)
        cout << dist[t] << '\n';
    else
        cout << "unreachable\n";
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

    int tt;
    cin >> tt;
    REP(i, 1, tt, 1)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}