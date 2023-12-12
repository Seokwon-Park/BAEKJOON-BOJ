#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genreCount;
    unordered_map<string, vector<pair<int, int>>> um;
    
    
    for(int i =0; i < genres.size(); i++)
    {
        genreCount[genres[i]] += plays[i];
        um[genres[i]].push_back({plays[i],i});
    }
    
    vector<pair<string, int>> mvec(genreCount.begin(), genreCount.end());
    
    sort(mvec.begin(), mvec.end(), [](pair<string, int> a, pair<string, int> b)
         {
            return a.second > b.second; 
         });    
    
    
    for(auto p:mvec)
    {
        sort(um[p.first].begin(), um[p.first].end(), cmp);
        if(um[p.first].size() >=2 )
        {
            for(int i =0; i< 2; i++)
            {
                answer.push_back(um[p.first][i].second);
            }
        }
        else
        {
            for(int i =0; i< um[p.first].size(); i++)
            {
                answer.push_back(um[p.first][i].second);
            }
        }
    }
    
    
    return answer;
}