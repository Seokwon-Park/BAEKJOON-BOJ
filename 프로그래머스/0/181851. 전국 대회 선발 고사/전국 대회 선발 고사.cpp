#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<pair<int,int>> attendee;
    for(int i = 0; i< rank.size();i++)
    {
        if(attendance[i])
            attendee.push_back({rank[i], i});
    }
    sort(attendee.begin(),attendee.end());
    
    answer += attendee[0].second *10000;
    answer += attendee[1].second *100;
    answer += attendee[2].second;
    
        
    
    return answer;
}