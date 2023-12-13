#include <bits/stdc++.h>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    unordered_map<char, bool> um;
    
    for(char c: skip)
    {
        um[c] = true;
    }
    
    for(char c: s)
    {
        for(int i = 0; i< index; i++)
        {
            c++;
            c = c > 'z'? c-26: c;
            while(um[c])
            {
                c++;
                c = c > 'z'? c-26: c;
            }
        }

        answer+=c;
    }
    
    return answer;
}