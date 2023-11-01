#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
       int answer = 0;

    int st = 1;
    int ed;
    int range = 0;
    for (int i = 0; i < stations.size(); i++)
    {
        ed = stations[i] - w;
        if (ed - st > 0)
        {
            int gap = ed - st;
            if (gap % (w * 2 + 1) == 0)
            {
                answer += gap / (w * 2 + 1);
            }
            else
            {
                answer += gap / (w * 2 + 1) + 1;
            }
        }
        st = stations[i] + w + 1;
    }

    if (n - st >= 0)
    {
        int gap = n - st +1;
        if (gap % (w * 2 + 1) == 0)
        {
            answer += gap / (w * 2 + 1);
        }
        else
        {
            answer += gap / (w * 2 + 1) + 1;
        }
    }

    return answer;
}