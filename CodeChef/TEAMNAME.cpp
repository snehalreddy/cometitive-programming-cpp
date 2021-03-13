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

        set<string> fH, fT, f;

        unordered_map<string, set<string>> hashMap1;

        string temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            f.insert(temp);
            fH.insert(temp.substr(0, 1));
            // fT.insert(temp.substr(1, temp.length()));
            hashMap1.insert(temp.substr(0, 1), temp);
        }

        unordered_map<string, set<string>>::iterator itr;
        for (itr = hashMap1.begin(); itr != hashMap1.end(); itr++)
        {
            cout << itr->first << ":" << endl;
        }
        cout << endl;

        // // do the combos
        // set<string> combos;
        // set<string>::iterator it;
        // set<string>::iterator itt;
        // for (it = fH.begin(); it != fH.end(); it++)
        // {
        //     for (itt = fT.begin(); itt != fT.end(); itt++)
        //     {
        //         // add them into a new set
        //         string newEle = string(*it).append(string(*itt));

        //         if (f.find(newEle) == f.end())
        //         {
        //             combos.insert(newEle);
        //         }
        //     }
        // }

        // set<string> ultCombos;
        // for (string c : combos)
        // {
        //     for (string cc : combos)
        //     {
        //         if ((c.substr(0, 1) != cc.substr(0, 1)) && (c.substr(1, cc.size()) != cc.substr(1, cc.size())))
        //         {
        //             ultCombos.insert(c + " " + cc);
        //             ultCombos.insert(cc + " " + c);
        //         }
        //     }
        // }

        // for (string c : ultCombos)
        // {
        //     cout << c << ", ";
        // }
        // cout << endl;

        // cout << ultCombos.size() << endl;

        // long long int cSize = combos.size();
        // if (cSize != 2 && cSize != 0)
        //     cout << nPr(cSize, 2) << endl;
        // else if (cSize == 0)
        //     cout << 0 << endl;
        // else
        //     cout << 2 << endl;
    }

    return 0;
}