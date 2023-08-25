#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class UnionFind
{
private:
    vi p, depth, setSize;
    int numSets;

public:
    UnionFind(int n)
    {
        setSize.assign(n + 1, 1);
        numSets = n;
        depth.assign(n + 1, 0);
        p.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        if (i == p[i])
            return i;
        return p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
    int numDisjointSets()
    {
        return numSets;
    }
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;
        int x = findSet(i), y = findSet(j);
        if (depth[x] > depth[y])
            swap(x, y);
        p[x] = y;
        if (depth[x] == depth[y])
            depth[y]++;
        setSize[y] += setSize[x];
        numSets--;
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

    TC
    {
    }

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}