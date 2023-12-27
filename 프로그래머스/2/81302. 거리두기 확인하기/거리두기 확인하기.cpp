#include <bits/stdc++.h>

using namespace std;

vector<string> board;

int dx1[4] = {-1,0,1,0};
int dy1[4] = {0,-1,0,1};
int dx2[4] = {-2,0,2,0,};
int dy2[4] = {0,-2,0,2};
int dx3[4] = {-1, 1,1,-1};
int dy3[4] = {1,-1,1,-1};

bool chk(int x, int y)
{
    for(int i =0; i<4; i ++) // 상하 좌우 케이스
    {
        int tx = x + dx1[i];
        int ty = y + dy1[i];
        if(tx < 0 || ty<0|| tx>=5|| ty>= 5) continue;
        if(board[ty][tx] == 'P') return false;
    }
    for(int i =0; i<4; i ++) // 상하 좌우 2칸 케이스
    {
        int tx = x + dx2[i];
        int ty = y + dy2[i];
        if(tx < 0 || ty<0|| tx>=5|| ty>= 5) continue;
        if(board[ty][tx] == 'P') 
        {
            if(board[(ty+y)/2][(tx+x)/2] != 'X')
                return false;
        }
    }
    for(int i =0; i<4; i ++) // 대각 케이스
    {
        int tx = x + dx3[i];
        int ty = y + dy3[i];
        if(tx < 0 || ty<0|| tx>=5|| ty>= 5) continue;
        if(board[ty][tx] == 'P') 
        {
            if(board[ty][x] != 'X' || board[y][tx] != 'X')
                return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto p:places)
    {
        bool isSafe = true;
        vector<pair<int,int>> posv; // x, y
        board = p;
        for(int i = 0 ;i < 5; i++)
        {
            for(int j =0;j < 5; j++)
            {
                if(p[i][j] == 'P')
                    posv.push_back({j,i});
            }
        }
        
        for(int i= 0; i< posv.size(); i++)
        {
            if(!chk(posv[i].first, posv[i].second))
            {
                isSafe = false;
                break;
            }
        }
        if(!isSafe) answer.push_back(0);
        else answer.push_back(1);
        
    }
    
    return answer;
}