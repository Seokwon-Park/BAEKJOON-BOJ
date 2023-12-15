#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    string burger = "1231";
    
    string list= "";
    int ix = 0;
    for(auto i:ingredient)
    {
        if(list.length()< 3)
        {
            list += i+'0';
            cout << list << '\n';
        }
        else
        {
            list += i+'0';            
            ix = list.find(burger, list.length()-4);
            if(ix != -1)
            {
                for(int i =0 ; i< 4; i++)
                {
                    list.pop_back();
                }
                answer++;
            }
            else
            {
                ix = 0;
            }
        }
    }
    
    return answer;
}