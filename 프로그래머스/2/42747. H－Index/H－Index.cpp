#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int h = 0;
    
    int a = *max_element(citations.begin(), citations.end());
    
    for(int i = 1; i <= a; i++)
    {
        auto itr = lower_bound(citations.begin(), citations.end(), i);
        if(itr - citations.begin() <= i && citations.end()-itr >=i)
        {
            if(i > h )
                h = i;
        }
        
    }
    answer = h;
    
    return answer;
}