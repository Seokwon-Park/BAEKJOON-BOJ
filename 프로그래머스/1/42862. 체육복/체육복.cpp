#include <bits/stdc++.h>

using namespace std;

int student[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    fill(student, student+n+1, 1);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
       
    for(auto i:lost)
    {
        student[i]--;
    }
    
    for(auto i:reserve)
    {
        student[i]++;
    }
    
    for(auto i:reserve)
    {
        if(student[i]>1)
        {
        if(student[i-1] == 0)
        {
            student[i-1] = 1;
            continue;
        }
        else if(student[i+1] == 0)        
        {
            student[i+1] = 1;
        }
        }
    }
    
    for(int i = 1; i<=n; i++)
    {
        if(student[i] >0)
            answer++;
    }
    
    return answer;
}