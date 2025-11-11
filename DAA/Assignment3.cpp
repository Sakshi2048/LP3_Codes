/*
0/1 Knapsack using Dynamic Programming

You are given:

weights[]
values[]
capacity W

Choose items such that:
1. Total weight ≤ W
2. Total value is maximized
3. Items cannot be taken fractionally → 0 or 1

We use a DP table where dp[i][w] = max profit using first i items with capacity w.
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val) {

    int n = val.size();

    vector <vector<int> > dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter Knapsack capacity: ";
    cin >> W;

    cout << "Maximum value = " << knapsack(W, wt, val);
    return 0;
}


/*

Sample Input 
---------------
3
weights: 10 20 30
values: 60 100 120
W = 50

Output : Maximum value = 220

Time Complexity : Dynamic Programming table has (n × W) cells. -  O(nW)
Space Complexity : DP table size = (n × W)


Applications - 
--------------
1) Resource allocation
2) Budget planning
3) Cargo loading
4) Project selection

*/