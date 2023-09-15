#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int num = s/n;
    int temp = s;
    for(int i =0 ; i< n; i++)
    {
        if(s < n)
        {
            temp = 0;
            answer.push_back(-1);
            break;
        }
        answer.push_back(num);
        temp -= num;
    }
    
    for(auto i:answer)
        cout << i << " ";
    
    int idx = 0;
    while(temp>0)
    {
        answer[idx]++;
        temp--;
        idx++;
        if(idx>=n)
            idx = 0;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
