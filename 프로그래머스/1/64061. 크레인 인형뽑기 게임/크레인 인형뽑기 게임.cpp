#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> b;
int h;
int w;

int getdoll(int x)
{
    int dol = 0;
    for(int i = 0 ;i <h; i++)
    {
        dol = b[i][x];    
        if(b[i][x] != 0)
        {
            dol = b[i][x];
            b[i][x] = 0;
            break;
        }
    }
    
    return dol;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> st;
    
    h = board.size();
    b = board;
    
    for(int m:moves)
    {
        int doll = getdoll(m-1);
        cout << doll << '\n';
        if(doll != 0)
        {
            //cout << doll << '\n';
            if(st.empty())
            {
                st.push_back(doll);
            }
            else
            {
                int tp = st.back();
                if(tp == doll)
                {
                    st.pop_back();
                    answer += 2;
                }
                else
                {
                    st.push_back(doll);
                }
            }
        }
    }    
    
    return answer;
}