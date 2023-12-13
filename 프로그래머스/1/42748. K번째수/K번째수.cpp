#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto cmd: commands)
    {
        int i = cmd[0];
        int j = cmd[1];
        vector<int> newvec(array.begin()+i-1, array.begin()+j);
        sort(newvec.begin(), newvec.end());
        answer.push_back(newvec[cmd[2]-1]);

    }
    
    return answer;
}