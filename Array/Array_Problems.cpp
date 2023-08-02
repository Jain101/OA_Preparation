#include <bits/stdc++.h>
using namespace std;

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
 * Date : 31.07.2023
 * Problem Link : https://leetcode.com/contest/weekly-contest-356/problems/count-complete-subarrays-in-an-array/
 * Approach : use brute force but optimised, travers all the subarrays and keep 3 things - vector<int> hasOccured to keep track of distinct ele, int ans to keep track of complete subarrays, int cnt to count distinct ele in each subarray, combine all this strategically and design the solution
 * TC : O(n^2)
 * SC : O(n)
 * Other Approaches :
 */
int countCompleteSubarrays(vector<int> &nums)
{
    int n = nums.size();
    set<int> s(all(nums));
    int distinct = s.size(), ans = 0;
    REP(i, 0, n - 1, 1)
    {
        int cnt = 0;
        vector<int> hasOccured(2001);
        REP(j, i, n - 1, 1)
        {
            cnt += !hasOccured[nums[j]];
            hasOccured[nums[j]] = 1;
            ans += (cnt == distinct);
        }
    }
    return ans;
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
        vi a(n);
        inputV(a);
        cout << countCompleteSubarrays(a);
    }

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}