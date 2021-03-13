#include <bits/stdc++.h>
#define MAX 1000200
#define sqrtOfMax 316
using namespace std;

// int cx, kCx, kPrimeMap[MAX];
// bool flag[MAX];
// int prime[300];
bool primeFlag[MAX] = {true};

void SieveEratosthenes(int L, int U)
{
    int i, j, k;
    memset(primeFlag, true, sizeof(primeFlag));
    primeFlag[0] = false;
    primeFlag[1] = false;
    k = sqrt(U) + 1;
    for (i = 2; i <= k; i++)
    {
        if (primeFlag[i])
        {
            for (j = i; (j * i) < U; j++)
            {
                primeFlag[j * i] = false;
            }
        }
    }
}

// void mySieveErato(int n)
// {
//     for (int i = 2; i <= n; i++)
//     {
//         if (primeFlag[i])
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 primeFlag[j] = false;
//             }
//         }
//     }
// }

int main()
{
    SieveEratosthenes(0, MAX);
    long long int consoli[MAX + 1] = {0};

    for (long long int i = 2; i <= MAX; i++)
    {
        // if (consoli[i] > y)
        // {
        //     break;
        // }
        if (primeFlag[i])
        {
            consoli[i] = consoli[i - 1] + 1;
        }
        else
        {
            consoli[i] = consoli[i - 1];
        }
    }
    // mySieveErato(MAX);
    int t;
    int x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &x, &y);

        if (y == 1 && x == 1)
        {
            printf("Chef\n");
            continue;
        }
        else if (y == 1 && (x == 2))
        {
            printf("Chef\n");
            continue;
        }
        else if (y == 1 && (x > 2))
        {
            printf("Divyam\n");
            continue;
        }


        // for(int i=0; i<=x; ++i) {
        //     cout << i << ":" << consoli[i] << "\t";
        // }
        // cout << endl;

        if (consoli[x] > y)
        {
            printf("Divyam\n");
            // cout << consoli[x] << " > " << y << endl;
        }
        else
        {
            printf("Chef\n");
            // cout << consoli[x] << " < " << y << endl;
        }
    }
    return 0;
}

