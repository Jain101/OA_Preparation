/**
 * We will use it mostly to iterate over subsets, I don't know much.
 * S = {1,2,...,N}
 * subsets = 2^N
 * Q. We have yo store all subsets in lesser memory
 * A1. we can use a bool array to check the presence of ele from 1toN
 * A2. got any idea from A1? it will lead to a binary representation, we can use binary representation and thier decimal values to represent subsets.
 *
 * Let's implement it in parts.
 * Assume : N=10, and we are given a subset value and we have to find that subset
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 5;
void insert(int &subset, int x)
{
    subset = subset | (1 << (x - 1));
}
void remove(int &subset, int x)
{
    subset = subset ^ (1 << (x - 1));
}
void display(int &subset)
{
    for (int bit_pos = 0; bit_pos <= 9; bit_pos++)
    {
        if (subset & (1 << bit_pos))
            cout << bit_pos + 1 << ' ';
    }
    cout << endl;
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

    int subsets[1 << N];
    for (int i = 0; i < (1 << N); i++)
        subsets[i] = i;
    display(subsets[15]);
    remove(subsets[15], 2);
    display(subsets[15]);
    insert(subsets[15], 5);
    display(subsets[15]);

#ifndef ONLINE_JUDGE
    cerr
        << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
        << "\n";
#endif
}