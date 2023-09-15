#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st; 
    for(auto ch: s)
    {
        if(ch == ')')
        {
            if(!st.empty() && st.top() != '(' )
                return false;
            else if(st.empty())
                return false;
            else                
                st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;
    if(!st.empty())
        return false;

    return answer;
}
