#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1000000000
/**
 * PUSH DP
 * dp[i]->no. of ways to get sum 'i' from {1,...,6}
 * ans=dp[n]
 * base case : dp[0]=1
 * dp[i]=sigma{dp[i-j], for all valid j}
 */
void diceCombinations()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i < j)
                break;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n];
}

/**
 * PUSH DP
 * dp[i]->min no. of coins to get sum 'i' from {coins}
 * ans=dp[n]
 * base case : dp[0]=0
 * dp[i] = min{dp[i-c],for all valid c in coins}
 */
void minimizingCoins()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int &c : coins)
        {
            if (i - c >= 0)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
}

/**
 * PUSH DP
 * dp[i]->no. of ways to get sum 'i' from {coins}, non-distinct ordered matters
 * ans=dp[x]
 * base case : dp[0]=1
 * dp[i]=sigma{dp[i-c], for all valid c}
 */
void coinCombinations_I()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int &c : coins)
        {
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % mod;
        }
    }
    cout << dp[x];
}
/**
 * PUSH DP
 * dp[i][x]->no. of distinct ordered ways to get sum 'x' using 1st 'i' coins
 * we are dealing with the ith coin here
 * ans=dp[n][x]
 * base case : dp[i][0]=1,dp[0][0]=0,d[0][x]=0
 * dp[i][x]=dp[i-1][x]+dp[i][x-coins[i]],for all x-coins[i]>=0 else 0
 * dp[i][x]=[don't pick ith coin]+[pick ith coin]
 */
void coinCombinations_II()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> coins[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++)
            dp[i][j] = (dp[i - 1][j] + (j - coins[i] >= 0 ? dp[i][j - coins[i]] : 0)) % mod;
    cout << dp[n][x];
}

/**
 * PUSH DP
 * dp[i][x]->no. of distinct ordered ways to get sum 'x' using 1st 'i' coins
 * we are dealing with the ith coin here
 * ans=dp[n][x]
 * base case : dp[i][0]=1,dp[0][0]=0,d[0][x]=0
 * dp[i][x]=dp[i-1][x]+dp[i][x-coins[i]],for all x-coins[i]>=0 else 0
 * dp[i][x]=[don't pick ith coin]+[pick ith coin]
 */
int dp[1000001];
void prep()
{
    dp[0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[i] = 1;
}
void removeDigits()
{
    int n;
    cin >> n;
    prep();
}
/**
 * Date : 09.08.2023
 * PUSHDP:
 * dp[i][j]->no. of paths from [0][0] to [i][j]
 * ans=dp[n-1][n-1]
 * BASECASE: if(g[0][0]='.') dp[0][0]=1
 * dp[i][0]=d[0][j]=1
 *  else dp[0][0]=0
 * dp[i][0]=d[0][j]=0
 * we could reach [i][j] from [i-1][j] or [i][j-1]
 * RECURSIVECASE: dp[i][j]=dp[i-1][j]+dp[i][j-1],for all valid i,j
 * dp[i][x]=[don't pick ith coin]+[pick ith coin]
 */
void gridPaths()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));
    // dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] % mod;
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] % mod;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << dp[n - 1][n - 1] % mod;
}

/**
 * Date : 10.08.2023
 * PUSHDP:
 * dp[i][j]->no. of paths from [0][0] to [i][j]
 * ans=dp[n-1][n-1]
 * BASECASE: if(g[0][0]='.') dp[0][0]=1
 * dp[i][0]=d[0][j]=1
 *  else dp[0][0]=0
 * dp[i][0]=d[0][j]=0
 * we could reach [i][j] from [i-1][j] or [i][j-1]
 * RECURSIVECASE: dp[i][j]=dp[i-1][j]+dp[i][j-1],for all valid i,j
 * dp[i][x]=[don't pick ith coin]+[pick ith coin]
 */
void arrayDescription()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
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

    gridPaths();

#ifndef ONLINE_JUDGE
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
         << "\n";
#endif
}