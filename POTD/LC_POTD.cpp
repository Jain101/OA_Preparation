#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 19.07.2023 - https://leetcode.com/problems/non-overlapping-intervals/description/
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int lat_end = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            if (x >= lat_end)
            {
                count++;
                lat_end = y;
            }
        }
        return n - count;
    }
};