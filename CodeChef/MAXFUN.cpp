#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        long long int N;
        cin >> N;

        long long int a[N];
        for (long long int n = 0; n < N; n++)
        {
            cin >> a[n];
        }

        // sort(a, a+N);
        // cout << 2 * (a[N - 1] - a[0]) << endl;
        cout << 2 * (*max_element(a, a + N) - *min_element(a, a + N)) << endl;
    }
}