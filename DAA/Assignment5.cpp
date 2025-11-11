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

// ------------------------ Deterministic Pivot (First Element) ------------------------
int partitionDet(vector<int> &a, int low, int high)
{
    int pivot = a[low]; // pivot is now the FIRST element
    int i = low + 1;    // start comparing from next element
    int j = high;

    while (true)
    {
        // Move i right while a[i] <= pivot
        while (i <= j && a[i] <= pivot)
            i++;

        // Move j left while a[j] > pivot
        while (i <= j && a[j] > pivot)
            j--;

        if (i <= j)
            swap(a[i], a[j]);
        else
            break;
    }

    // Place pivot at its correct position
    swap(a[low], a[j]);
    return j;
}

void quickSortDet(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partitionDet(a, low, high);
        quickSortDet(a, low, pi - 1);
        quickSortDet(a, pi + 1, high);
    }
}

// ------------------------ Randomized Pivot ------------------------
int partitionRand(vector<int> &a, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(a[randomIndex], a[low]); // random pivot now acts like deterministic (first element)
    return partitionDet(a, low, high);
}

void quickSortRand(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partitionRand(a, low, high);
        quickSortRand(a, low, pi - 1);
        quickSortRand(a, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n), arr2(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    arr2 = arr; // copy for randomized version

    cout << "\nDeterministic Quick Sort (Pivot = First Element):\n";
    quickSortDet(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";

    cout << "\n\nRandomized Quick Sort:\n";
    quickSortRand(arr2, 0, n - 1);
    for (int x : arr2)
        cout << x << " ";

    return 0;
}

/*
Sample Input :
--------------
8
10 7 8 9 1 5 12 3

Output :
--------
Deterministic Quick Sort (Pivot = First Element):
1 3 5 7 8 9 10 12
Randomized Quick Sort:
1 3 5 7 8 9 10 12
*/