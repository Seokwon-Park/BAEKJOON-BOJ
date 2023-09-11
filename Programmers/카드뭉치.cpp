#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int ix1 = 0;
    int ix2 = 0;
    int ptr = 0;
    while (ptr < goal.size())
    {
        if (ix1<cards1.size() && cards1[ix1] == goal[ptr])
        {
            ix1++;

        }
        else if (ix2 <cards2.size() && cards2[ix2] == goal[ptr])
        {
            ix2++;

        }
        else
        {
            return "No";
        }
        ptr++;
    }

    return "Yes";
}
