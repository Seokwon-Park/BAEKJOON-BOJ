#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    set<int> st;
    
    for(auto str:operations)
    {
        char op = str[0];
        if(op == 'I')
        {
            int value = stoi(str.substr(2, str.length()-1));
            st.insert(value);
        }
        else
        {

            int value = stoi(str.substr(2, str.length()-1));
            if(value == -1)
            {
                //cout << pq_down.top()<< endl;
                st.erase(*st.begin());
            }
            else
            { 
                //cout << pq_up.top()<< endl;
                st.erase(*st.rbegin());                
            }            
        }
        for( auto a:st)
        {
            cout << a << " ";
        }
        cout << endl;

    }
    
    if(st.size() <=0)
    {
        answer.push_back(0);
        answer.push_back(0);        
    }
    else
    {
        answer.push_back(*st.rbegin());
        answer.push_back(*st.begin());
        
    }
    
    

    return answer;
}
