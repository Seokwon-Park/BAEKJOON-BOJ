#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    replace(s.begin(), s.end(), '{', ',');
    replace(s.begin(), s.end(), '}', ',');
    replace(s.begin(), s.end(), ',', ' ');

    string number = "";

    for (char c : s)
    {
        if (c != ' ')
        {
            number += c;
        }
        else
        {
            if (number.length() > 0)
            {
                m[stoi(number)]++;
                number = "";
            }
        }
    }

    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) 
        {
            return a.second > b.second;
        });

    for (auto v : vec)
    {
        answer.push_back(v.first);
    }

    return answer;
}