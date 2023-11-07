#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> wmap;
    unordered_map<string, int> dmap;
    for(int i =0; i<want.size(); i++)
    {
        wmap[want[i]] = number[i];
    }
    
    for(int i = 0; i+10<=discount.size(); i++)
    {
        dmap = wmap;
        bool is_same = false;
        for(int j = i; j<i+10; j++)
        {
            dmap[discount[j]]--;
        }
        is_same = true;
        for(auto str:want)
        {
            if(dmap[str] > 0)
            {
                is_same = false;
                break;
            }
        }
        if(is_same)
        {
            answer++;
        }
    }
    
    return answer;
}