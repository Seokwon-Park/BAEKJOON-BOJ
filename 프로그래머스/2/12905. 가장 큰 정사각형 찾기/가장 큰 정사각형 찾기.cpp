#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    
    int h = board.size();
    int w = board[0].size();
    
    int max = 0;
    for(int i =1; i<= h; i++)
    {
        for(int j =1; j<= w; j++)
        {
            if(board[i-1][j-1] != 0)
            {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
                if(dp[i][j] > max)
                {
                    max = dp[i][j];
                }
            }
        }
    }

    return max * max;
}