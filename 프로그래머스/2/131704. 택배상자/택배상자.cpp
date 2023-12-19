#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    vector<int> box = order;
    sort(box.begin(), box.end());
    stack<int> st;
    
    int seq = 0;
    for(int i = 0; i< order.size(); i++)
    {
        while(order[i] > box[seq])
        {
            st.push(box[seq]);
            seq++;
        }
        if(order[i] == box[seq])
        {
            answer++;
        }
        else if(st.top() == order[i])
        {
            answer++;
            st.pop();
        }
        else
        {
            break;
        }
    }
    
    return answer;
}