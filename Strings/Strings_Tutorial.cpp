#include <bits/stdc++.h>
using namespace std;

/**
 * Problem : Count unique strings in a string vector
 * 1. Brute Force Approach : sort the strings lxly, count the partitions by comparing the strings
 * TC : O(nmlogn + nm) ~ O(nmlogn)
 * SC :
 * 2. Hashing : give every string a hash value(O(nm)), and then sort the values(nlogn) and count distincts(O(n))
 * TC : O(nm+nlogn+n) ~ O(nm)
 */
const int N = 1e5 + 1, m = 1e9 + 7, p = 31;
vector<long long> powers(N);
int bruteCount(vector<string> &strs)
{
    int n = strs.size();
    if (n == 0 || n == 1)
        return n;
    sort(strs.begin(), strs.end());
    int distinct = 1;
    for (int i = 1; i < n; i++)
    {
        if (strs[i] != strs[i - 1])
            distinct++;
    }
    return distinct;
}

long long calcHash(string &s)
{
    long long value = 0;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        (value += (s[i] - 'a' + 1) * powers[i]) % m;
    }
    return value;
}
int hashCount(vector<string> &strs)
{
    int n = strs.size();
    // preprocessing powers
    powers[0] = 1;
    for (int i = 1; i < N; i++)
    {
        powers[i] = (powers[i - 1] * p) % m;
    }
    // calculating hash values for each s in vector<string>
    vector<long long> hashValues;
    for (string &s : strs)
    {
        hashValues.push_back(calcHash(s));
    }
    // counting distinct hash values
    sort(hashValues.begin(), hashValues.end());
    int distinct = 1;
    for (int i = 1; i < n; i++)
    {
        if (hashValues[i] != hashValues[i - 1])
            distinct++;
    }
    return distinct;
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
    while (tt--)
    {
        int n;
        cin >> n;
        vector<string> strs(n, "");
        for (string &s : strs)
            cin >> s;
        cout << hashCount(strs);
    }

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}