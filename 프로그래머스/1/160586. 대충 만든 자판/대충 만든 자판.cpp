#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    unordered_map<char, int> um; // Key, Times; 각 키에 대해서 눌러야 하는 최소값 해쉬로 저장
        
    for(int j = 0; j< keymap.size(); j++)
    {
        for(int i =0; i< keymap[j].length(); i++)
        {
            if(um.find(keymap[j][i]) != um.end()) // 이미 해당 키에 대한 값이 있으면 
                //누르는 횟수 비교
            {
                if(um[keymap[j][i]] > i+1)
                {
                    um[keymap[j][i]] = i+1;
                }
            }
            else
            {
                um[keymap[j][i]] = i+1;
            }
        }
    }
    
    for(string t: targets)
    {
        int times = 0;
        for(char c: t)
        {
            if(um.find(c) == um.end()) 
            {
                times = -1;
                break;
            }
            times+= um[c];
        }
        answer.push_back(times);
    }
    
    return answer;
}