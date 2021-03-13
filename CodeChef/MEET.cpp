#include <bits/stdc++.h>
using namespace std;

string addTwelve(string s)
{
    return s.replace(0, 2, to_string(stoi(s.substr(0, 2)) + 12));
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        string meet_at[2];
        cin >> meet_at[0] >> meet_at[1];
        // cout << endl << meet_at[0] << " " << meet_at[1] << endl;
        // cout << stoi(meet_at[0].substr(0, 2)) << endl;
        // cout << addTwelve(meet_at[0]) << endl;

        if (meet_at[0].substr(0, 2) == "12")
        {
            meet_at[0].replace(0, 2, "00");
        }
        if (meet_at[1] == "PM")
        {
            // meet_at[0] += 12;
            meet_at[0] = addTwelve(meet_at[0]);
        }
        // cout << meet_at[0] << endl;

        int N;
        cin >> N;

        string free_sch[N][4];
        for (int n = 0; n < N; n++)
        {
            cin >> free_sch[n][0] >> free_sch[n][1] >> free_sch[n][2] >> free_sch[n][3];
            if (free_sch[n][0].substr(0, 2) == "12")
            {
                // cout << "Before transform: " << free_sch[n][0] << free_sch[n][1] << endl;
                free_sch[n][0].replace(0, 2, "00");
                // cout << "After transform: " << free_sch[n][0] << free_sch[n][1] << endl;
            }
            if (free_sch[n][2].substr(0, 2) == "12")
            {
                // cout << "Before transform: " << free_sch[n][2] << free_sch[n][3] << endl;
                free_sch[n][2].replace(0, 2, "00");
                // cout << "After transform: " << free_sch[n][2] << free_sch[n][3] << endl;
            }

            if (free_sch[n][1] == "PM")
            {
                // free_sch[n][0] += 12;
                free_sch[n][0] = addTwelve(free_sch[n][0]);
            }
            if (free_sch[n][3] == "PM")
            {
                // free_sch[n][2] += 12;
                free_sch[n][2] = addTwelve(free_sch[n][2]);
            }
        }

        string ans = "";
        for (int i = 0; i < N; i++)
        {
            // cout << "First cond: " << (free_sch[i][0] > free_sch[i][2]) << endl;
            // cout << "Second cond: " << (free_sch[i][0].compare(meet_at[0]) <= 0) << "&&" << (free_sch[i][2].compare(meet_at[0]) >= 0) << endl;

            // if (free_sch[i][0] > free_sch[i][2])
            // {
            //     // cout << "First: " << free_sch[i][0] << " - " << free_sch[i][2] << endl;
            //     ans.append("0");
            // }
            // else
            if (free_sch[i][0].compare(meet_at[0]) <= 0 && free_sch[i][2].compare(meet_at[0]) >= 0)
            {
                // cout << "Second: " << free_sch[i][0] << " - " << free_sch[i][2] << endl;
                ans.append("1");
            }
            else
            {
                // cout << "Third: " << free_sch[i][0] << " - " << free_sch[i][2] << endl;
                ans.append("0");
            }
        }

        cout << ans << endl;
    }

    return 0;
}