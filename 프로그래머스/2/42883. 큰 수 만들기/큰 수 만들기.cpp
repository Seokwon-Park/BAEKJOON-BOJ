#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int del_num = k;
    vector<char> s;
    for(char num: number)
    {
        while(s.size() > 0 && del_num > 0 && s.back() < num)
        {
            s.pop_back();
            del_num--;
        }
        s.push_back(num);
    }
    
    while(del_num>0)
    {
        s.pop_back();
        del_num--;
    }
    
    for(char c:s)
    {
        answer+= c;
    }   
    
    return answer;
}