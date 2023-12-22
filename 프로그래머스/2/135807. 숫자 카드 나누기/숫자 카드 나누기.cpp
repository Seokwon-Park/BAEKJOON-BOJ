#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int na = arrayA.size();
    int nb = arrayB.size();
    int ga;
    int gb;
    
    if(na == 1) 
    {
        ga = arrayA[0];
    }
    if(nb == 1)
    {
        gb = arrayB[0];
    }
    else
    {
        ga = gcd(arrayA[0], arrayA[1]);
        gb = gcd(arrayB[0], arrayB[1]);
    }
        
    
    for(int i =2 ;i <na; i++)
    {
        ga = gcd(ga, arrayA[i]);
    }
    for(int i =2 ;i <nb; i++)
    {
        gb = gcd(gb, arrayB[i]);
    }
    
    bool aSuccess = true;
    bool bSuccess = true;
    
    for(int i = 0 ;i <na; i++)
    {
        if(arrayA[i] % gb == 0) 
        {
            aSuccess = false;
        }
    }
    for(int i = 0 ;i <nb; i++)
    {
        if(arrayB[i] % ga == 0)
        {
            bSuccess = false;
        }
    }
    
    if(aSuccess && bSuccess)
    {
        return gb>ga? gb : ga;
    }
    else if(aSuccess)
    {
        return gb;
    }
    else if(bSuccess)
    {
        return ga;
    }
    else
    {
        return 0;
    }
    
   
    return answer;
}