#include <bits/stdc++.h>

using namespace std;

bool checker(string str)
{
    stack<char> s;

    for (auto ch : str)
    {
        if (ch == '[' || ch == '{' || ch == '(')
        {
            s.push(ch);
        }
        else if(!s.empty())
        {
            char c = s.top();
            s.pop();
            if (ch == ']')
            {
                if (c != '[')
                    return false;
            }
            if (ch == '}')
            {
                if (c != '{')
                    return false;
            }
            if (ch == ')')
            {
                if (c != '(')
                    return false;
            }
        }
        else
        {
            return false;
        }
    }
    if (s.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length(); i++)
    {
        string fr = s.substr(0, i);
        string ba = s.substr(i, s.length());

        string tmp = ba + fr;
        
        if (checker(tmp))
        {
            answer++;
        }
    }

    return answer;
}