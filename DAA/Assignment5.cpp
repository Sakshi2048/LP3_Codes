/*
QUICK SORT ANALYSIS


What is Deterministic Quick Sort?

You always choose a fixed pivot → usually:
last element
first element
or middle element

This can lead to worst-case O(n²) for already sorted arrays.

-------------------------------------------------

What is Randomized Quick Sort?

Pivot is chosen randomly using rand() → reduces chances of worst case.
Average time becomes O(n log n) reliably.


*/

#include <bits/stdc++.h>
using namespace std;

// ------------------------ Deterministic Pivot ------------------------
int partitionDet(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortDet(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partitionDet(a, low, high);
        quickSortDet(a, low, pi - 1);
        quickSortDet(a, pi + 1, high);
    }
}

// ------------------------ Randomized Pivot ------------------------
int partitionRand(vector<int> &a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(a[randomIndex], a[high]); // random pivot
    return partitionDet(a, low, high);
}

void quickSortRand(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partitionRand(a, low, high);
        quickSortRand(a, low, pi - 1);
        quickSortRand(a, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n), arr2(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    arr2 = arr;  // copy for randomized version

    cout << "\nDeterministic Quick Sort:\n";
    quickSortDet(arr, 0, n - 1);
    for (int x : arr) cout << x << " ";

    cout << "\n\nRandomized Quick Sort:\n";
    quickSortRand(arr2, 0, n - 1);
    for (int x : arr2) cout << x << " ";

    return 0;
}


/*
Sample Input :
--------------
8
10 7 8 9 1 5 12 3

Output :
--------
Deterministic Quick Sort:
1 3 5 7 8 9 10 12 
Randomized Quick Sort:
1 3 5 7 8 9 10 12




TIME COMPLEXITY ANALYSIS

1) Deterministic Quick Sort
-------------------------------------------------------
| Case    | Time                                      |
| ------- | ----------------------------------------- |
| Best    | O(n log n)                                |
| Average | O(n log n)                                |
| Worst   | **O(n²)** (sorted or reverse-sorted list) |
-------------------------------------------------------


2) Randomized Quick Sort
--------------------------------------------
| Case    | Time                           |
| ------- | ------------------------------ |
| Best    | O(n log n)                     |
| Average | **O(n log n)** (almost always) |
| Worst   | O(n²) but extremely unlikely   |
--------------------------------------------

Randomization avoids the worst-case patterns.

Space Complexity
----------------
Due to recursion stack: O(log n) (average)
Worst case: O(n)

*** quick sort is not stable.

*/