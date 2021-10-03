/*
    Problem URL : https://codeforces.com/problemset/problem/1579/E1
*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int size;
    cin >> size;
    deque<int> finalSequence;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        // First Element
        if (i == 0)
        {
            finalSequence.push_back(x);
        }
        // Arranging
        else
        {
            // If Number is smaller than the first number
            if (x < finalSequence[0])
            {
                finalSequence.push_front(x);
            }
            // If Number is greater than the first number
            else
            {
                finalSequence.push_back(x);
            }
        }
    }
    // Output
    for (int i = 0; i < size; i++)
    {
        cout << finalSequence[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

/*
    Input : 
    3
    4
    3 2 1 4
    2
    2 1 
    2
    1 2
    OutPut : 
    1 2 3 4
    1 2
    1 2


    Time Complexity - O(n)
    Space Complexity - O(n)
*/