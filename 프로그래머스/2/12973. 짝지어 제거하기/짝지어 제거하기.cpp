#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;

    for(char c: s)
    {
        if(st.empty())
        {
            st.push(c);
        }
        else if(st.top() != c)
        {
            st.push(c);
        }
        else if(st.top() == c)
        {
            st.pop();
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    if(st.empty()) answer = 1;
    else
        answer = 0;

    return answer;
}