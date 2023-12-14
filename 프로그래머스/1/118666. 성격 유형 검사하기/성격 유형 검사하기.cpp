#include <bits/stdc++.h>

using namespace std;

string table[4] = {"RT", "CF", "JM", "AN"};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> um;
    
    for(int i =0; i< survey.size(); i++)
    {       
        char l = survey[i][0];
        char r = survey[i][1];
        if(choices[i] > 4)
        {
            um[r] += choices[i]-4;
        }
        else if(choices[i] <4)
        {
            um[l] += 4-choices[i];
        }            
    }
    for(int i =0; i< 4; i++)
    {
        char l = table[i][0];
        char r = table[i][1];
        
        if(um[l] < um[r])
        {
            answer+= r;
        }
        else
        {
            answer+=l;
        }
    }    
    
    
    return answer;
}