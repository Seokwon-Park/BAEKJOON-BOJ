#include <bits/stdc++.h>

using namespace std;



vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> m;
    m["code"] = 0;
    m["date"] = 1;
    m["maximum"] = 2;
    m["remain"] = 3;
    

    for(auto d:data)
    {
        int n = m[ext];
        if(d[n] <val_ext)
        {
            answer.push_back(d);
        }        
    }
    
    int n = m[sort_by];    
    sort(answer.begin(), answer.end(), [n](vector<int>& arr1, vector<int>& arr2)
         {
            return arr1[n] < arr2[n] ;
         });
    return answer;
}