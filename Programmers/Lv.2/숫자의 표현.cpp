#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i< n/2+1; i++)
    {
        int tmp = 0;

        for(int j = i; j <= n; j ++)
        {
            tmp += j;
            if(tmp > n) break;
            else if(tmp == n)
            {
                answer++; break;
            }
        }
    }
    answer++;
    
    return answer;
}
