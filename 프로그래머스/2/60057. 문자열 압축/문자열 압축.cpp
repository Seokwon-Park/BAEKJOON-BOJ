#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;    
    
    int n = s.length();
    for(int i =1; i <= n; i ++)
    {
        int cnt = 0;
        int len = 0;
        string pattern;
        for(int j =0; j< n ;)
        {
            pattern = s.substr(j,i);
            if(s.find(pattern,j) != -1)
            {
                cout << s.find(pattern,j) << ' ' << pattern << '\n';
                cnt++;
                j += pattern.length();
            }
            else
            {
                pattern = s.substr(j,i);
                if(cnt > 1)
                {
                    len+=2;   
                }
                else
                {
                    len +=1;
                }
            }           
        }
        cout << len;
        if(len < answer)
        {
            answer = len;
        }
    }

    return answer;
}