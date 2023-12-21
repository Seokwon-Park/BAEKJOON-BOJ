#include <string>
#include <vector>
#include <iostream>

using namespace std;

int board[1100][1100];
int one = 0;
int zero = 0;

int partition(int x, int y, int n)
{
    if(n == 1)
    {
        if(board[y][x] == 1) one++;
        else zero++;
        return board[y][x];
    }
    int half = n/2;
    int p1 = partition(x,y,half);
    int p2 = partition(x+half, y, half);
    int p3 = partition(x, y+half, half);
    int p4 = partition(x+half, y+half, half);
    if(p1 ==1 && p2 == 1 && p3 == 1 && p4 == 1)
    {
        one += 1;
        one -= 4;
        return 1;
    }
    else if(p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0)
    {
        zero += 1;
        zero -= 4;
        return 0;
    }    
    else
    {  
        return 2;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    int n = arr.size();
    for(int i =0 ;i< n; i++)
        for(int j =0 ;j< n; j++)
        {
            board[i][j] = arr[i][j];
        }
    
    partition(0, 0, n);
    
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}