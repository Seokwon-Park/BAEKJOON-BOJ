#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    char lastch;
    // i%3 + 1
    for(int i = 0; i< words.size(); i++)
    {
        if(lastch != words[i][0] && i !=0)
        {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
        }
        if(m[words[i]] > 0)
        {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
        }
        string word = words[i];
        lastch = word[word.length()-1];
        m[words[i]]++;
    }
    
    
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}