class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c:s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else if(c == ')' || c == '}' || c == ']')
            {
                if(st.empty()) return false;
                else 
                {
                    char ch = st.top();
                    if(ch == '(' && c == ')')st.pop();
                    else if(ch == '{' && c == '}')st.pop();
                    else if(ch == '[' && c == ']')st.pop();
                    else return false;
                }
            }
        }
        if(!st.empty()) return false;        
        else return true;
    }
};
