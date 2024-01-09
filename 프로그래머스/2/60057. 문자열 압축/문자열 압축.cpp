#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;    
    
    int n = s.length();
    if(n ==1)
    {
        return 1;
    }
    for(int i =1; i <= n/2; i ++)
    {
        int cnt = 0;
        int len = 0;
        string pattern;
        string newstr = "";
        string prev_pattern = s.substr(0,i);
        for(int j =0; j< n ;)
        {
            pattern = s.substr(j,i);
            if(pattern == prev_pattern) // 이전패턴과 같으면 개수 추가
            {
                //cout << s.find(pattern,j) << ' ' << pattern << '\n';
                cnt++;
                j += pattern.length();
            }
            else // 아닌경우
            {
                if(cnt > 1)
                {
                    newstr += to_string(cnt);
                    newstr += prev_pattern; 
                    cnt = 0; 
                    len+=2; 
                }
                else
                {
                    newstr += prev_pattern;
                    cnt= 0;
                    len +=1;
                }
                prev_pattern = s.substr(j,i);  
                
            }                  
        }
        if(cnt > 1)
        {
            newstr += to_string(cnt);
            newstr += prev_pattern; 
            cnt = 0; 
            len+=2; 
        }
        else
        {
            newstr += prev_pattern;
            cnt= 0;
            len +=1;
        }
        if(newstr.length() < answer)
        {
            answer = newstr.length();
        }
    }

    return answer;
}