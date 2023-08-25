#include <bits/stdc++.h>
using namespace std;

#define int long long
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

/**
 * Date : 11.08.2023
 * Problem : https://codeforces.com/contest/1850/problem/E
 * TC : O(n*log(1e9)) ~ O(n)
 */
int binarySearch(vi &s, int c)
{
    int n = s.size();
    int l = 1, h = 1e9, m;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        int sum = 0;
        REP(i, 0, n - 1, 1)
        {
            sum += (s[i] + 2 * m) * (s[i] + 2 * m);
            if (sum > c)
                break;
        }
        if (sum > c)
            h = m - 1;
        else if (sum == c)
            return m;
        else
            l = m + 1;
    }
    return -1;
}

void solve()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, c;
        cin >> n >> c;
        vi s(n);
        inputV(s);
        cout << binarySearch(s, c) << '\n';
    }
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