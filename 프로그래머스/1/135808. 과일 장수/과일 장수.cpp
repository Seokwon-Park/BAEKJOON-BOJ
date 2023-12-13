#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    int n = score.size();
    sort(score.begin(), score.end(), [](int a, int b) { return a>b;});
    
    int cnt = 0;
    int min = INT_MAX;
    for(int i = 0 ; i< n; i++)
    {
        cnt++;
        if(score[i] < min)
            min = score[i];
        if(cnt >= m)
        {
            answer+= min*m;
            cnt = 0;
            min = INT_MAX;
        }
        
        
    }
    
    return answer;
}