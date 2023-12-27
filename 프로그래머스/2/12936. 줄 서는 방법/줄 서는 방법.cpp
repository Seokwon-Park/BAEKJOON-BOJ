#include <bits/stdc++.h>

using namespace std;

long long dp[22]; 

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    dp[0] = 1;
    dp[1] = 1;
    for(int i =2; i<=n;i ++)
    {
        dp[i] = dp[i-1]*i;
    }
    
    vector<int> arr;
    for(int i = 1; i<= n ; i++)
    {
        arr.push_back(i);
    }
    
    long long kk = k-1;
    for(int i = 1; i<=n; i++)
    {
        long long pos = kk/dp[n-i];
        kk = kk % dp[n-i];
        answer.push_back(arr[pos]);
        arr.erase(arr.begin() + pos);
    }
    
    return answer;
}