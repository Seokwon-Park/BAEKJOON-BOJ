#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0,1, 0};
int dy[4] = {0, -1,0, 1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    for(int i = 0; i< 4; i++)    
    {
        string current = board[h][w];
        int tx = w + dx[i];
        int ty = h + dy[i];        
        if(tx <0 || ty<0 || ty >= board.size() || tx >= board[0].size()) continue;
        if(board[ty][tx] == current)
        {
            answer++;
        }
    }
    
    
    return answer;
}