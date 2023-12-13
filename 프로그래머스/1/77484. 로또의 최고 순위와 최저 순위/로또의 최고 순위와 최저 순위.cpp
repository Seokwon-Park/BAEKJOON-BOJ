#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int correct = 0;
    int poss= 0;
    
    sort(lottos.begin(), lottos.end(), [](int a, int b){return a>b;});
    
    for(int i = 0; i< lottos.size(); i++)
    {
        if(lottos[i] == 0)
        {
            poss++;
        }
        else if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            correct++;
        }        
    }
    
    int max = 7 -(correct+poss);
    int min = 7 -correct;
    if(max > 6) max = 6;
    if(min > 6) min = 6;
    
    answer.push_back(max);
    answer.push_back(min);
    
    
    return answer;
}