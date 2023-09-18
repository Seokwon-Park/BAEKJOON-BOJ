// 2차원 배열 시각화 하려고 코드 쓴거 안지워서 효율성 통과못함.
// 응 BFS, DFS쓰면 지워도 시간초과남 ㅋ

/* //DP에서 쓰면 안되는 코드 
#include <bits/stdc++.h>

using namespace std;

int block[105][105];
int dp[105][105];

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0; i< puddles.size(); i++)
    {
        block[puddles[i][0]-1][puddles[i][1]-1]= true;
    }

    queue<pair<int,int>> Q;
    Q.push(make_pair(0,0));
    dp[0][0] = 1;
    while(!Q.empty())
    {
        pair<int,int> cur_pos = Q.front();
        Q.pop();
        for(int i =0; i< 2; i++)
        {
            int tx = cur_pos.first+dx[i];
            int ty = cur_pos.second+dy[i];
            if(tx >= m || ty >= n) continue;
            if(block[tx][ty]) continue;
            //cout << tx << " " << ty << endl;
            if(ty == 0) dp[tx][ty] = dp[tx-1][ty];
            else if(tx == 0) dp[tx][ty] = dp[tx][ty-1];
            else dp[tx][ty] = dp[tx-1][ty] + dp[tx][ty-1];
            
            Q.push(make_pair(tx,ty));
        }
        //cout << endl;
    }
    
    for(int i =0; i<n; i++)
    {
        for (int j =0; j<m; j++)
        {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
        
    answer = dp[m-1][n-1] %1000000007;
    
    return answer;
}*/

#include <bits/stdc++.h>

using namespace std;

int dp[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    dp[0][0] = 1;    
  
    for(auto puddle:puddles)
    {
        dp[puddle[0]-1][puddle[1]-1] = -1;
    }  
    
    for(int i =0; i< m; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(dp[i][j] == -1) 
            {
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0)
            {
                continue;
            }
            if(i == 0)
            {
                dp[i][j] = dp[i][j-1];
            }
            else if(j ==0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= 1000000007;
            }
        }
    }
    
    //for(int i =0; i<n; i++)
    //{
    //    for (int j =0; j<m; j++)
    //    {
    //        cout << dp[j][i] << " ";
    //    }
    //    cout << endl;
    //}
    
    answer = dp[m-1][n-1];
    
    return answer;
}
