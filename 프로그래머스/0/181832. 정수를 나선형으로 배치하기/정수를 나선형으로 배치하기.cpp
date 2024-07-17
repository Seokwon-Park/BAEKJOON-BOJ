#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int dir = 2;
    int cx = 0;
    int cy = 0;
    int num = 1;
    while(num <= n*n)
    {
        answer[cy][cx] = num++;
        int tx = cx + dx[dir];
        int ty = cy + dy[dir];
        if(tx <0 || ty <0 || tx >= n || ty>=n || answer[ty][tx] != 0)
        {
            dir = (dir+1)%4;
            tx = cx + dx[dir];
            ty = cy + dy[dir];
        }
        cx = tx;
        cy = ty;
    }
    
    return answer;
}