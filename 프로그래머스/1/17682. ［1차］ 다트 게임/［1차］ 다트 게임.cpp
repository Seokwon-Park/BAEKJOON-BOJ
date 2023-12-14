#include <bits/stdc++.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    unordered_map<int, int> um; // seq, score;
    
    string num = "";
    int seq = 0;
    for(auto c: dartResult)
    {
        if(isdigit(c))   
            num+= c;   
        else
        {
            if(num.length())
            {
                seq++;
                um[seq] = stoi(num);
                num = "";
            }
            if(c == 'D')
            {
                um[seq] *= um[seq];
            }
            else if(c == 'T')
            {
                um[seq] *= um[seq] *um[seq];
            }
            else if(c == '*')
            {
                um[seq] *=2;
                um[seq-1] *= 2;
            }
            else if( c == '#')
            {
                um[seq] *= -1;
            }
        }
    }
    
    for(auto k: um)
    {
        answer += k.second;
    }
    
    return answer;
}