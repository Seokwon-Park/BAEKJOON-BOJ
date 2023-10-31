#include <bits/stdc++.h>

using namespace std;

int danger[105][105];
int dx[8] = {-1,0,1,0,1, 1, -1, -1};
int dy[8] = {0,-1,0,1,-1, 1, 1, -1};


int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    for(int i =0; i<n; i++)
    {
        for(int j =0; j< n; j++)
        {
            if(board[i][j] == 1)
            {
                danger[i][j] = 1;
                for(int k =0; k< 8; k++)
                {
                    if(i+dx[k] < 0 || i+dx[k] > n-1 || j+dy[k] < 0 || j+dy[k] > n-1)
                        continue;
                    if(danger[i+dx[k]][j+dy[k]] ==1) continue;                    
                    danger[i+dx[k]][j+dy[k]] = 1;
                }
            }
        }
    }
    
    for(int i =0; i<n; i++)
    {
        for(int j =0; j< n; j++)
        {
            cout << danger[i][j];
            if (danger[i][j] == 0)
                answer++;
        }
        cout << '\n';
    }
    
    return answer;
}