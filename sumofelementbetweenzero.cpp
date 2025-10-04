#include "bits/stdc++.h"
using namespace std;

void sumBetweenZero(int arr[], int N)
{

    int i = 0;

    // To store the sum of element
    // between two zeros
    vector<int> A;

    // To store the sum
    int sum = 0;

    // Find first index of 0
    for (i = 0; i < N; i++) {
        if (arr[i] == 0) {
            i++;
            break;
        }
    }

    // Traverse the given array arr[]
    for (; i < N; i++) {

        // If 0 occurs then add it to A[]
        if (arr[i] == 0) {
            A.push_back(sum);
            sum = 0;
        }

        // Else add element to the sum
        else {
            sum += arr[i];
        }
    }

    // Print all the sum stored in A
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ' ';
    }

    // If there is no such element print -1
    if (A.size() == 0)
        cout << "-1";
}

// Driver Code
int main()
{
    int arr[] = { 1, 0, 3, 4, 0, 4, 4,
                  0, 2, 1, 4, 0, 3 };

    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    sumBetweenZero(arr, N);
    return 0;
}
