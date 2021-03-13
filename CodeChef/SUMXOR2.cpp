#include <bits/stdc++.h>
using namespace std;

#define int long long

/*         n --> No. of elements present in input array.  
    BITree[0..n] --> Array that represents Binary Indexed Tree. 
    arr[0..n-1] --> Input array for which prefix sum is evaluated. */

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] = BITree[index] ^ val;

        // Update index to that of parent in update View
        index += index & (-index);
    }
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    // Store the actual values in BITree[] using update()
    for (int i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);

    // Uncomment below lines to see contents of BITree[]
    // for (int i=1; i<=n; i++)
    //     cout << BITree[i] << " ";

    return BITree;
}

// Driver program to test above functions
signed main()
{
    int t;
    cin >> t;

    int freq[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &freq[i]);
    }
    // int freq[] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};
    // int freq[] = {1, 3, 5, 2};
    int n = sizeof(freq) / sizeof(freq[0]);
    // int *BITree = constructBITree(freq, n);
    // cout << "Sum of elements in arr[0..5] is "
    //      << getSum(BITree, 3);

    // Let use test the update operation
    // freq[3] += 6;
    // updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]

    // cout << "\nSum of elements in arr[0..5] after update is "
    //      << getSum(BITree, 5);

    // Pre-compute all the k's till 't' here
    int preSum[t + 1];
    preSum[1] = freq[0];
    for (int i = 1; i < t; i++)
    {
        preSum[1] = preSum[1] ^ freq[i];
    }

    cout << preSum[1] << endl;

    // int q, m;
    // scanf("%d", &m);

    // while (q--)
    // {
    //     scanf("%d", &m);

    // }

    return 0;
}
