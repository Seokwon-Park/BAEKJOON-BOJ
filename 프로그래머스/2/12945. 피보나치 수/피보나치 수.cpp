#include <bits/stdc++.h>

using namespace std;

int dp[100005];

int solution(int n) {
    int answer = 0;
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i =2; i<=n; i++)
    {
        dp[i] = (dp[i-1]% 1234567)+(dp[i-2]% 1234567);
    }

    answer = dp[n]%1234567;
    //cout <<dp[n];
    return answer;
}