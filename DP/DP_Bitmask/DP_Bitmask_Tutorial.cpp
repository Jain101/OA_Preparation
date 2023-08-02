/**
 * Date : 01.08.2023
 * Problem : Job assigment problem https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbFgyd1FsVE9xbnpNZ2FzSHdzZEl4OEpVS1FjZ3xBQ3Jtc0trX3lUMFgxa3phbThaZFdyRWFiN3cxUDZwQXVicm9aWmxSN3lmQXBzd3BWbGpzY3l6Nmd2Ulg3UWpxNHE0RDRwaDVHVy1QaEVaemNFTzlVVTg3bkdRM3JnVVJSVVM3amFiR25obzNxbDVvNm8xU00xaw&q=https%3A%2F%2Fdocs.google.com%2Fdocument%2Fd%2F1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8%2Fedit%3Fusp%3Dsharing&v=685x-rzOIlY
 * dp[mask][i] : minimum cost to assign job 'i' to jth person hidden inside mask(check jth bit on)
 * dp[mask][i] = min {cost[j][i]+dp[mask/j][i+1], for all valid j}
 *
 * TC : O(N*2^N)
 * SC : O(N^2*2^N)
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

int cost[21][21];
int dp[1 << 21][21];
int solve(int mask, int i, int &n)
{
    if (i == n + 1)
        return 0;
    if (dp[mask][i] != -1)
    {
        return dp[mask][i];
    }
    dp[mask][i] = INT_MAX;
    for (int j = 1; j <= n; j++)
    {
        if (mask & (1 << (j - 1)))
        {
            dp[mask][i] = min(dp[mask][i], cost[j][i] + solve(mask ^ (1 << (j - 1)), i + 1, n));
        }
    }
    return dp[mask][i];
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

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> cost[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << solve((1 << n) - 1, 1, n) << '\n';
    }

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}