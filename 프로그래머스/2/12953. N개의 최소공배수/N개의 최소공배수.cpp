#include <bits/stdc++.h>

using namespace std;

int gcd(int n1, int n2)
{
    int a = n1;
    int b = n2;
    int r;
    while(a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    int n = arr[0];
    int lcm = arr[0];
    for(int i = 1; i< arr.size(); i++)
    {   
        int g = gcd(lcm, arr[i]);
        lcm *= arr[i];
        lcm /= g;
    }
    answer = lcm;
   
    return answer;
}