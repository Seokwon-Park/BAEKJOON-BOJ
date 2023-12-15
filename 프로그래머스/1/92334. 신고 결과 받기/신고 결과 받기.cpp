#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
      
    unordered_map<string, set<string>> reportList;
    unordered_map<string, pair<int, vector<string>>> reportedTimes;
    unordered_map<string, int> mail;
    
    for(auto id: id_list)
    {
        mail[id] = 0;
    }
    
    for(auto r:report)
    {
        int split_pos = 0;
        for(int i =0 ;i < r.length(); i++)
        {  
            if(r[i] == ' ') 
            {
                split_pos = i;
            }
        }
        string a = r.substr(0, split_pos);
        string b = r.substr(split_pos+1);
        
        reportList[a].insert(b); // a= 신고자, b = 신고당한사람
    }    
    
    for(auto report:reportList)
    {
        for(auto b:report.second)
        {
            reportedTimes[b].first++; // 신고당한 사람에 대한 신고횟수++
            reportedTimes[b].second.push_back(report.first); // 신고자에 대한 이름을 넣음.
        }
    }
    
    for(auto r:reportedTimes)//신고횟수 기록에 대해서
    {
        if(r.second.first >= k) // 신고를 k번 이상 당했다?
        {
            for(auto name:r.second.second)
            {
                mail[name]++; //이사람을 신고한 사람들 한테 메일 1번.
            }
        }
    }
    
    for(auto id:id_list)
    {
        answer.push_back(mail[id]);   
    }   
    return answer;
}