#include <bits/stdc++.h>

using namespace std;

int board[105][105];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int n = 1;
    for(int i =1; i<= rows; i++)
    {
        for(int j =1; j<= columns; j++)
        {
            board[i][j] = n++;
            //cout << board[i][j] << ' ';
        }
        //cout << '\n';
    }
    
    for(auto q:queries)
    {
        int x1 = q[0];
        int y1 = q[1];
        int x2 = q[2];
        int y2 = q[3];
        
        vector<int> le;
        vector<int> ri;
        vector<int> up;
        vector<int> dn;
        
        set<int> elems; // 이걸로 최솟값 찾을꺼임
        
        // 이걸로 회전에 쓸거임
        for(int l = x1+1; l<= x2; l++)
        {
            le.push_back(board[l][y1]);
            elems.insert(board[l][y1]);
        }
        
                
        for(int r = x2-1; r>= x1; r--)
        {
            ri.push_back(board[r][y2]);
            elems.insert(board[r][y2]);          
        }
        
                
        for(int u = y2-1; u>= y1; u--)
        {
            up.push_back(board[x1][u]);
            elems.insert(board[x1][u]);          
            
        }
        
        for(int d = y1+1; d<= y2; d++)
        {
            dn.push_back(board[x2][d]);
            elems.insert(board[x2][d]);          
        }
        
        answer.push_back(*min_element(elems.begin(),elems.end()));
        
        //회전 적용시키기
        for(int l = x1; l < x2; l++)
        {
            board[l][y1] = le[l-x1];
        }
        
        for(int r = x2; r > x1; r--)
        {
            board[r][y2] = ri[x2-r];
        }
        
        for(int u = y2; u > y1; u--)
        {
            board[x1][u] = up[y2-u];
        }
        
        for(int d = y1; d < y2; d++)
        {
            board[x2][d] = dn[d-y1];
        }
        
        /*for(int i =1; i<= rows; i++)
        {
            for(int j =1; j<= columns; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }*/
        
    }
    
    return answer;
}