#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    long long f = sqrt(n);
    if(f*f == n)
    {
        answer = (f+1) *(f+1);
    }

    return answer;
}