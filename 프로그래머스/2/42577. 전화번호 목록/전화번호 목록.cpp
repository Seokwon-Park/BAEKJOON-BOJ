#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, bool> um;
    
    for(string num:phone_book)
    {
        um[num] = true;
    }
    
    for(string num:phone_book)
    {
        string substring = "";        
        for(int j= 0; j< num.length(); j++)
        {            
            substring += num[j];
            if(um[substring] && substring != num)
            {
                return false;
            }
        }       
    }
    

    
    return answer;
}