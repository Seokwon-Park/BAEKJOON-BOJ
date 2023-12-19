#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int cur = INT_MIN;
    
    sort(targets.begin(), targets.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });
    
    for(auto t:targets)
    {
        //cout << t[0] << ' ' << t[1] << '\n';
        if(t[0] >= cur) // 지금 막대의 끝보다 작은시작점 + 끝나는 지점을 기준으로
            // sort를 했기때문에 cur의 끝나는 지점보다 길다는게 보장되기 때문에 같이 부술수 있음.
        {
            cur = t[1];
            answer++;
        }
    }
    
    return answer;
}