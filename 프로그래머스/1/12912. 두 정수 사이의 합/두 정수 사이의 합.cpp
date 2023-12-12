#include <bits/stdc++.h>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    long long cnt = abs(a-b)+1;
    
    if(cnt % 2 == 1)
    {
        long long mid = (a+b)/2;
        answer = cnt*mid;
    }
    else
    {
        long long sum = a+b;
        answer= sum*cnt /2;
    }
    
    return answer;
}