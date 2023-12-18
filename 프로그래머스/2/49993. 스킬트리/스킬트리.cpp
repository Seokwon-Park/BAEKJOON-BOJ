#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int n = skill_trees.size();
    
    unordered_map<char, int> um;
    
    int ix = 1;
    for(char c: skill)
    {
        um[c] = ix;
        ix++;
    }
    
    for(int i =0; i<n; i++)
    {
        int ix = 1; // 처음 배워야 하는 스킬 인덱스
        bool isLearnable = true;
        for(auto c:skill_trees[i])
        {
            if(um[c] != 0)// 선행트리가 있는 스킬을 배울 경우
            {
                if(um[c] == ix) // 배워야하는 인덱스와 일치하면
                {
                    ix++; // 다음 스킬 인덱스로
                }
                else // 아닐경우 잘못된 스킬트리임
                {
                    isLearnable = false;
                    break;
                }
            }
        }
        
        //for문에서 걸리지 않았으면 스킬트리에 문제가 없다는뜻.
        if(isLearnable) answer++;
    }
    
    return answer;
}