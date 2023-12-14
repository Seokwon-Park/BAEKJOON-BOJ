#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> lpos = { 0, 3 };
    pair<int, int> rpos = { 2, 3 };

    unordered_map<int, pair<int, int>> um;

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
            um[i] = { 1,3 };
        else
            um[i] = { (i-1) % 3 ,(i-1) / 3 };
    }

    for (int n : numbers)
    {
        if (n == 1 || n == 4 || n == 7)
        {
            lpos = um[n];
            answer += 'L';
        }
        else if (n == 3 || n == 6 || n == 9)
        {
            rpos = um[n];
            answer += 'R';
        }
        else
        {
            int ldist = abs(um[n].first - lpos.first) + abs(um[n].second - lpos.second);
            int rdist = abs(um[n].first - rpos.first) + abs(um[n].second - rpos.second);

            if (ldist > rdist)
            {
                rpos = um[n];
                answer += 'R';
            }
            else if(ldist< rdist)
            {
                lpos = um[n];
                answer += 'L';
            }
            else if (ldist == rdist)
            {
                if (hand == "right")
                {
                    rpos = um[n];
                    answer += 'R';
                }
                else
                {
                    lpos = um[n];
                    answer += 'L';
                }
            }

            //cout << ldist << ' ' << rdist << '\n';
        }
    }
    return answer;
}