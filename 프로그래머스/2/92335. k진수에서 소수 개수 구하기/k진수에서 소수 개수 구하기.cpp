#include <bits/stdc++.h>

using namespace std;


bool chksosu(long long num)
{
    if(num==1 || num == 0) return false;
    for(long long i = 2; i*i <= num; i++)
    {
        if(num % i ==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;    
    
    vector<int> jinsu;
    int div = k;
    while(n >0)
    {
        jinsu.push_back(n%div);
        n/=div;            
    }
    
    //reverse(jinsu.begin(), jinsu.end());
    
    long long val =0;
    long long dec = 1;
    for(auto j:jinsu)
    {
        if(j != 0)  
        {
            val += j*dec;
            dec *= 10;
        }
        else
        {
            //cout << val << '\n';
            if(chksosu(val)) answer++;
            dec = 1;
            val = 0;
        }
    }
    if(val != 0)
    {
        //cout << val;
        if(chksosu(val)) answer++;
    }    
    
    return answer;
}