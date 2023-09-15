#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";

    int min = INT_MAX;
    int max = -INT_MAX;
    
    string a = "-1";
    s+= ' ';
        
    string tmp = "";
    for(auto ch: s)
    {
        if(ch == ' ')
        {
            if (stoi(tmp) < min)
                min = stoi(tmp);
            if(stoi(tmp)> max)
                max = stoi(tmp);
            tmp = "";
            continue;
        }
        tmp += ch;       
    }
    
    answer = to_string(min) + ' ' + to_string(max);
    
    return answer;
}
