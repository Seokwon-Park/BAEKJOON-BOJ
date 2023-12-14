#include <bits/stdc++.h>

using namespace std;

bool chk()
{
    
}

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> blist = {"aya", "ye", "woo", "ma" };
    unordered_map<string, int> um;
    

    for(string babb: babbling)
    {
        string prev_babb = "";
        bool a = true;
        while(babb.length())
        {
            bool isfind = false;
            for(string b: blist)
            {
                int n = b.length();
                string tmp = babb.substr(0, n);
                if(tmp == b && prev_babb != b) 
                {
                    isfind = true;
                    babb = babb.substr(n);
                    prev_babb = b;
                    break;
                }                
            }
            if(!isfind)
            {
                a = false;
                break;
            }
        }
        if(a) answer++;
    }
    
    return answer;
}