#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    
    for(long long i = left; i <= right; i++)
    {
        int x = i%n+1;
        int y = i/n+1;
        int xy = y > x ? y : x;
        
        answer.push_back(xy);
    }

    return answer;
}