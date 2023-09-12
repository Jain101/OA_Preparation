#include <bits/stdc++.h>
using namespace std;

#define int long long int
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

#define inputV(v, a)       \
    REP(_, a, v.size()-1, 1) \
    {                      \
        cin >> v[_];       \
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

/**bipartite check - "graph is bicolored in such a way that no 2 exact neighbors 
 * share the same color"
 * # Assumptions:
 * 1. graph is connected
 * 2. graph is numbered from 1 to N(no. of nodes)
 * 
 * #conclusions:
 * 1. A tree is always bipartite
 * 2. A graph with odd cycle is non-bipartite(or bipartite graph has no odd cycle)
 * 3. 
*/
void solve(){
    int n,m; cin>>n>>m;
    map<int,vi> adj;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool isBipartite=true;
    vi color(n+1,-1);
    queue<int> q;
    q.push(1);
    color[1]=0;
    while(!q.empty() && isBipartite){
        int u = q.front();
        q.pop();
        for(auto& v: adj[u]){
            if(color[v]==color[u]){
                isBipartite=false;
                break;
            }
            else if(color[v]==-1){
                color[v] = 1-color[u];
                q.push(v);
            }

        }
    }
    cout<<check(isBipartite);
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

    solve();

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}