#include <bits/stdc++.h>
using namespace std;

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