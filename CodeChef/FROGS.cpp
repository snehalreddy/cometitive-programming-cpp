#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int T;
    cin >> T;

    for (long long int t = 0; t < T; t++)
    {
        int N;
        cin >> N;

        int w[N];
        for (int i = 0; i < N; i++)
        {
            cin >> w[i];
        }

        int l[N];
        for (int i = 0; i < N; i++)
        {
            cin >> l[i];
        }

        int p[N + 1];
        for (int i = 1; i <= N; i++)
        {
            p[i] = 1 + distance(w, find(w, w + N, i));
            // cout << 1 + distance(w, find(w, w + N, i)) << ", ";
        }

        int count = 0;
        for (int i = 1; i < N; i++)
        {
            // cout << "Loop: " << i << endl;
            
            // cout << "Current number: " << i << ", at " << p[i] << endl;
            if (p[i] >= p[i + 1])
            {
                // calculate difference
                int diff = p[i] - p[i + 1];
                // cout << "Diff of " << i << ": " << diff << endl;

                // find the count = diff/lengthUnit
                int tempCount = floor(diff / l[p[i + 1] - 1]) + 1;
                count += tempCount;
                // cout << "Length found: " << l[p[i + 1] - 1] << endl;
                // cout << "Count calculated: " << tempCount << endl;

                // add count*length to p[i+1]
                // cout << "Count to add p[i+1]: " << p[i + 1] << " is " << (tempCount * l[p[i + 1] - 1]) << endl;
                p[i + 1] += tempCount * l[p[i + 1] - 1];
            }
        }
        cout << count << endl;

        // cout << endl;
    }

    return 0;
}