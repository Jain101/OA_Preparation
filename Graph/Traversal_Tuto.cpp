#include <bits/stdc++.h>
using namespace std;

// initialization technique
class Solution
{
private:
    vector<vector<int>> visited;
    vector<vector<int>> dist;
    map<int, vector<int>> adjList;
    //... 
    void init()
    {
        vector<vector<int>> v(501, vector<int>(501));
        vector<vector<int>> d(501, vector<int>(501));
        auto visited = v;
        auto dist = d;
        adjList.clear();
    }
    //... 
    void dfs()
    {
        //...
    }
public:
    vector<vector<int>> f()
    {
        init();
        //... 
        dfs();
        //...
    }
};


// single source BFS
int visited[1001];
int dist[1001];
int t[1001];
map<int, vector<int>> adjList;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int &neighbour : adjList[x])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                dist[neighbour] = dist[x] + 1;
                t[neighbour] = t[x] + 1;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    // initialization
    adjList.clear();
    memset(visited, 0, sizeof visited);
    memset(dist, 0, sizeof dist);
    memset(t, 0, sizeof t);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] << ' ';
    }
}

/*... 
int components = 0;
for (int i = 1; i <= n; i++)
{
    if (!visited[i])
    {
        components++;
        bfs(i);
    }
}
...*/

// multi source BFS
