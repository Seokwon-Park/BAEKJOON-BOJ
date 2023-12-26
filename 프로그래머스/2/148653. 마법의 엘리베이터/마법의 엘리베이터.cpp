#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    string stor = to_string(storey);
    
    for(int i = stor.length() - 1; i >= 1 ; i--)
    {
        int a = abs(10-(stor[i] - '0'));
        int b = stor[i] - '0';
        answer += a >= b? b:a;
        
        if(stor[i-1] < '9')
        {
            stor[i-1] = stor[i]+1;
        }
        else
        {
            stor[i-1] = '0';
        }
    }


    
    return answer;
}