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

bool func(ll x, ll N)
{
    return x * x <= N;
}

int binarySearch(vi &a, int t)
{
    int n = a.size();
    int l = 0, h = n - 1, m;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (a[m] == t)
            return m;
        else if (a[m] < t)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

bool isSquare(int n)
{
    int l = 1, h = n / 2, m;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (m * m - n == 0)
            return true;
        else if (m * m - n < 0)
            l = m + 1;
        else
            h = m - 1;
    }
    return false;
}

int first_true(vi &a, int x)
{
    int n = a.size();
    int l = 0, h = n - 1, m, ans = -1;

    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (a[m] >= x)
        {
            h = m - 1;
            ans = a[m];
        }
        else if (a[m] < x)
            l = m + 1;
    }
    return ans;
}

int smallestInRotatedArray(vi &a)
{
    int n = a.size();
}

ll last_true(ll lo, ll hi, ll N)
{
    // lo--;
    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2; // to prevent INT overflow + infinite loop
        if (func(mid, N))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    inputV(a);
    sort(all(a));
    int m = a[n / 2];
    REP(p, 0, k - 1, 1)
    {
        REP(i, n / 2, n - 1, 1)
        {
            if (a[i] == m)
            {
                a[i]++;
                if (a[i + 1] != m || i + 1 == n)
                {
                    m++;
                }
                break;
            }
        }
    }
    cout << m << '\n';
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
        int n, x;
        cin >> n >> x;
        vi a(n);
        inputV(a);
        cout << first_true(a, x);
    }

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}