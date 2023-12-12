#include <bits/stdc++.h>

using namespace std;

int mygcd(int a, int b)
{
    int r = a%b;
    if (r == 0) return b;
    return mygcd(b,r);
}

vector<int> solution(int n, int m) {
    vector<int> answer = {mygcd(n, m), n*m/mygcd(n,m)};
       
    
    return answer;
}