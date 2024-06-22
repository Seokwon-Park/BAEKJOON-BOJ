#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    
    vector<int> a(26,0);
    for(auto s: spell)
    {
        a[s[0]-'a']++;
    }
    
    bool isFind = false;
    for(auto s: dic)
    {
        vector<int> ac = a;
        for(auto c: s)
        {
            ac[c-'a'] --;
            if(ac[c-'a'] <0)
                break;
        }
        if(count(ac.begin(),ac.end(), 0) ==26)
        {
            isFind= true;
            return 1;
        }
    }
    
    
    return 2;
}