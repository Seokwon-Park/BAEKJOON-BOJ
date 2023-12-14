#include<bits/stdc++.h>

using namespace std;

int divNum(int a)
{
    int count = 0;
    int b = sqrt(a);
    if( a == 1 ) return 1;
    if(a == b*b) count++;
    for(int i =1; i*i < a; i++)
    {
        if(a% i == 0)
        {
            count+=2;
        }
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i<=number; i++)
    {
        int n = divNum(i);
        if(n >limit) n = power;
        answer+= n;
    }
    
    return answer;
}