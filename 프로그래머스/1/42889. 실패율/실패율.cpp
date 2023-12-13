#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    sort(stages.begin(), stages.end());
        
    vector<pair<int, double>> pvec;// {stage, 실패율}
    double failed = 0;
    double total = 0;
    for(int i = 1; i<= N; i++)
    {
        auto low= lower_bound(stages.begin(), stages.end(), i);
        auto upp= upper_bound(stages.begin(), stages.end(), i);
        failed = upp-low;            
        total = stages.end() - low;

        pvec.push_back(make_pair(i, failed/total));
    }
    
    stable_sort(pvec.begin(), pvec.end(), [] (pair<int,double> a, pair<int,double> b)
         {
             if(a.second == b.second)
             {
                 return a.first < b.first;
             }
             return a.second > b.second;
         });
    
    for(auto p: pvec)
    {
        answer.push_back(p.first);
    }
        
    return answer;
}