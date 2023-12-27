#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    unordered_map<int, bool> is_exist;
    unordered_map<int, long long> cnt;

    for (int w : weights)
    {
        cnt[w]++;
    }
    //1:1
    for (auto c : cnt)
    {
        if (c.second >= 2)
            answer+= c.second*(c.second-1)/2;
    }
    //2:3, 3:4, 2:4 = 1:2
    for (int w : weights) 
    {
        if(w % 2 == 0)
        {
            int tmp = w/2*3;
            answer += cnt[tmp];
        }
        if(w % 3 == 0)
        {
            int tmp = w/3*4;
            answer += cnt[tmp];
        }
        int tmp = w*2;
        answer += cnt[tmp];
    }


    return answer;
}