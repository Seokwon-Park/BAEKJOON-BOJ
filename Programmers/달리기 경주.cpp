#include <bits/stdc++.h>

using namespace std;

void Swap(string* a, string* b)
{
    string temp = *a;
    *a = *b;
    *b = temp;    
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    unordered_map<string, int> m;
    
    for(int i = 0; i< players.size(); i++)
    {
        m[players[i]] = i;
    }
    
    for(auto str: callings)
    {
        int ix = m[str];
        m[str]--;
        m[players[ix-1]]++;
        Swap(&players[ix], &players[ix-1]);
        
    }

    
    return players;
}

//핵심은 player index를 빨리 찾을 방법을 구한다(bubble sort 했다가 실패함)
