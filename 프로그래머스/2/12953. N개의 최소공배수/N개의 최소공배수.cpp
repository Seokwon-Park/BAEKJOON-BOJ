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
    int lcm;
    for(int i = 1; i< arr.size(); i++)
    {   
        lcm = n*arr[i];
        cout << lcm <<endl;
        n = gcd(n, arr[i]);
        cout << n << endl;
        lcm /= n;
    }
    answer = lcm;
   
    return answer;
}