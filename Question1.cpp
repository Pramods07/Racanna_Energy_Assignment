#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findSum(int x[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += x[i];
    }
    return sum;
}
/*Brute Force Approach
 Time Complexity-> O(n*m) (since traversing both arrays of their size n&m).
 */
bool solution_1(int a[], int b[], int m)
{
    // Find sum of elements in arrays a and b
    int sum1 = findSum(a, m);
    int sum2 = findSum(b, m);

    int newSum1, newSum2; // Variables to store new sums
    for (int i = 0; i < m; i++)
    { // Iterate through array a
        for (int j = 0; j < m; j++)
        {                                 // Iterate through array b
            newSum1 = sum1 - a[i] + b[j]; // Calculate new sum for a
            newSum2 = sum2 + a[i] - b[j]; // Calculate new sum for b
            if (newSum1 == newSum2)
            {                // If sums are equal
                return true; // if the sum of both the Arrays are equal then we return true
            }
        }
    }
    return false;
}

/*another Approach(using set)
Time Complexity;-> O(n)*/
// Function to swap values in two arrays
bool solution_2(int a[], int b[], int m)
{
    // Calculate sum of arrays
    int sum1 = findSum(a, m);
    int sum2 = findSum(b, m);

    // Find target difference to check the swap condition
    int targetDiff = (sum2 - sum1) / 2;

    // Create a set from array b
    unordered_set<int> bSet(b, b + m);

    // Loop through array a
    for (int num = 0; num < m; num++)
    {
        // Calculate complement
        int complement = a[num] + targetDiff;

        // Check if complement is in set b
        if (bSet.find(complement) != bSet.end())
        {
            // If so, return true
            return true;
        }
    }

    // If no swap is found, return false
    return false;
}

/*Another approach using Sorting arrays
Time complexity->O(n)*/
bool solution_3(int a[], int b[], int m)
{
    int sum1 = findSum(a, m);
    int sum2 = findSum(b, m);
    // Call for sorting the arrays
    sort(a, a + m);
    sort(b, b + m);

    // Note that target can be negative
    int target = sum1 - sum2;
    if (target % 2 != 0)
    {
        return false;
    }

    // target 0 means, answer is not possible
    if (target / 2 == 0)
        return false;

    int i = 0, j = 0;
    while (i < m && j < m)    // Iterate through arrays
    {
        int diff = a[i] - b[j];   //Calculate difference
        if (diff == target / 2)
        {
            return true;
        }

        // Look for a greater value in a[]
        else if (diff < target / 2)
            i++;

        // Look for a greater value in b[]
        else
            j++;
    }
    return false;
}

int main()
{                        
    int m;               // To store the size of arrays
    cin >> m;            // Get size of arrays from user
    int *a = new int[m]; // Dynamically allocate memory for array 'a'
    int *b = new int[m]; // Dynamically allocate memory for array 'b'

    for (int i = 0; i < m; i++)
    { // Loop to input elements of array 'a'
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    { // Loop to input elements of array 'b'
        cin >> b[i];
    }

    cout << solution_1(a, b, m); // Call solution_1 and print result
    cout << solution_2(a, b, m); // Call solution_2 and print result
    cout << solution_3(a, b, m); // Call solution_3 and print result

    delete[] a; // Deallocate memory of array 'a'
    delete[] b; // Deallocate memory of array 'b'
    return 0;   // Return from main function
}