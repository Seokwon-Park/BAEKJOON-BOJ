#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool firstFlag = true;
    
    for(auto ch: s)
    {
        if(firstFlag)
        {
            answer += toupper(ch);
            firstFlag = false;
        }
        else
        {
            answer += tolower(ch);   
        }           
        if(ch == ' ')
        {
            firstFlag = true;        
        }
        
    }
    
    return answer;
}
