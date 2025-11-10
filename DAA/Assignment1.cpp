#include <bits/stdc++.h>
using namespace std;

int fibIter(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibRec(int n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Iterative Fibonacci: " << fibIter(n) << endl;
    cout << "Recursive Fibonacci: " << fibRec(n) << endl;

    return 0;
}


/*

Iterative Fibonacci 
- Generate Fibonacci numbers using a loop by storing only the last two values.

TC : O(n) — loop runs n times
SC : O(1) — only 3 integer variables used

Recursive 
- The function calls itself twice, forming an exponential recursion tree.

TC : O(2ⁿ) — duplicates many subproblems
SC : O(n) — function calls stored in recursion stack

-----------------------------------------------------------------------
| Method    | Time Complexity | Space Complexity | Notes              |
| --------- | --------------- | ---------------- | ------------------ |
| Recursive | O(2ⁿ)           | O(n)             | Slow, simple logic |
| Iterative | O(n)            | O(1)             | Fast & efficient   |
-----------------------------------------------------------------------

*/