#include <bits/stdc++.h>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    
    long long lw = w;
    long long lh = h;
    answer = lw*lh - (lw+lh-gcd(lh,lw));
    return answer;
}