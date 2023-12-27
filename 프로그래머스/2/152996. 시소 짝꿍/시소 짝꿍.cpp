#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    unordered_map<int, bool> is_exist;
    unordered_map<int, int> cnt;

    for (int w : weights)
    {
        cnt[w]++;
    }
    for (auto c : cnt)
    {
        if (c.second >= 2)
            answer += c.second*(c.second-1)/2;
    }
    sort(weights.begin(), weights.end());

    weights.erase(unique(weights.begin(), weights.end()));

    for (int w : weights)
    {
        for (int i : {w * 2, w * 3, w * 4})
        {
            if (is_exist[i])
                answer++;
            else
            {
                is_exist[i] = true;
            }
        }
    }


    return answer;
}