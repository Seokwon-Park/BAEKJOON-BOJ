#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    for(int i: arr)
    {  
        if(st.empty())
        {
            st.push(i);
        }
        else
        {
            if(i == st.top())
                continue;
            else
                st.push(i);
        }
    }
    while(!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}