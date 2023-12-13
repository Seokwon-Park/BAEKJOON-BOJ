#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> dict;
    for(int i = 0; i< 26;i++)
    {
        string a = "";
        a += 'A'+i;
        dict[a] = i+1;
    }
    
    int cursor = 27;
    
    for (int i = 0; i < msg.length(); i++)
    {
        string str = "";
        str += msg[i];
        int ix = 1;
        int last_find;
        bool is_end = false;
        while (dict.find(str) != dict.end())
        {
            if (i + ix < msg.length())
            {
                last_find = dict[str];
                str += msg[i + ix];
                ix++;
            }
            else
            {
                last_find = dict[str];
                is_end = true;
                break;
            }
        }
        answer.push_back(last_find);
        if (dict.find(str) == dict.end())
        {
            dict[str] = cursor++;
            i += ix - 2;
        }
        if(is_end) break;
    }
    
   
    return answer;
}