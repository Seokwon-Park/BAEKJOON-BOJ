#include <bits/stdc++.h>

using namespace std;

int timetoint(string str)
{
    int hr = stoi(str.substr(0,2))*60;
    hr += stoi(str.substr(3,2));
    return hr;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    
    for(auto time:book_time)
    {
        int st = timetoint(time[0]);
        int ed = timetoint(time[1]);
        cout << st << ' ' <<  ed << '\n';
    }
    
    return answer;
}