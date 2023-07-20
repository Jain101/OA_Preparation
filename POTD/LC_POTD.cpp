#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * Date : 19.07.2023
     * Problem : https://leetcode.com/problems/non-overlapping-intervals/description/
     * Approach : Knapsack problem just sort by end and count as per the condition
     */
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
    /*
     * Analysis
     * TC - O(nlogn) + O(n) ~ O(nlogn)
     * SC - O(logn)[STL sort() uses a hybrid of Quick, Heap and Insertion Sort, with a WC SC O(log⁡n)]
     */

    /*
     * Date : 20.07.2023
     * Problem : https://leetcode.com/problems/asteroid-collision/post-solution/?submissionId=999179017
     * Approach : Stack problem so just consider all the cases and code it up
     */
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        vector<int> ans;
        for (int &ast : asteroids)
        {
            int flag = 1;
            while (!st.empty() && (st.top() > 0 && ast < 0))
            {
                int check = st.top() - abs(ast);
                if (check < 0)
                {
                    st.pop();
                    ans.pop_back();
                    continue;
                }
                else if (check == 0)
                {
                    st.pop();
                    ans.pop_back();
                }
                flag = 0;
                break;
            }
            if (flag)
            {
                st.push(ast);
                ans.push_back(ast);
            }
        }
        return ans;
    }
    /*
     * Analysis
     * TC - O(2*n) ~ O(n) : for every asteroid, we might do 2 operations at max - push and pop into the stack and that too only once.
     * SC - O(n) : worst case when no collision all are pushed into stack
     */
};