#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    int left = n;
    while(left != 0)
    {
    if(left%2 == 0)
    {
        left /= 2;
    }
    else
    {
        left -=1;
        ans++;
    }
    }
    
    return ans;
}