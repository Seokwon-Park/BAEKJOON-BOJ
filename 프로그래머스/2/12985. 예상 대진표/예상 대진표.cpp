#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    int aa = a;
    int bb = b;
    answer++;
    while((aa+1)/2 != (bb+1)/2 || abs(aa-bb) != 1)
    {
        aa = (aa+1)/2;
        bb = (bb+1)/2;
        answer++;
    }

    return answer;
}