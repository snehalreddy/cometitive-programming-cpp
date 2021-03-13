#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;

        int count = 0;

        int num = 5;
        for (int i = 2; i < n; i++)
        {
            num *= 5;
            if (n < num)
            {
                count += i - 2;
                break;
            }
        }
        cout << "Extras: " << count << endl;

        count += int(n / 5);
        cout << "Actual count including extras for " << n << ": " << count << endl;
    }

    return 0;
}