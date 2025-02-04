#include <string>
#include <vector>
#include <iostream>

using namespace std;

int m[105][105];

struct robot
{
    int r,c;
    int t;
    bool fin;
};

bool checkFin(vector<robot>& v, vector<vector<int>>& routes)
{
    for(int i = 0; i< v.size(); i++)
    {
        if(v[i].t != routes[i].size())
        {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<robot> v(routes.size());
    for(int i = 0; i< routes.size(); i++)
    {
        v[i].r = points[routes[i][0]-1][0];
        v[i].c = points[routes[i][0]-1][1];
        v[i].t = 1;
        v[i].fin = false;
        m[v[i].r][v[i].c] += 1;
    }
    for(int i = 1; i<= 100; i++)
    {
        for(int j = 1; j<= 100; j++)
        {
            if(m[i][j] >1)
            {
                answer++;
            }
        }
    }
    
    while(true)
    {
        if(checkFin(v, routes)) break;
    
        //움직임.
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i].t == routes[i].size())
            {
                if(v[i].fin == false)
                {
                    v[i].fin= true;
                    m[v[i].r][v[i].c] -= 1;
                }
                continue;
            }
            m[v[i].r][v[i].c] -= 1;
            int tr = points[routes[i][v[i].t]-1][0];
            int tc = points[routes[i][v[i].t]-1][1];
            if(tr != v[i].r)
            {
                if(tr > v[i].r)
                {
                    v[i].r++;
                }
                else
                {
                    v[i].r--;
                }
            }
            else if(tc != v[i].c)
            {   
              if(tc > v[i].c)
                {
                    v[i].c++;
                }
                else
                {
                    v[i].c--;
                }
            }
            m[v[i].r][v[i].c] += 1;
                       
            //cout << "robot" <<i << ": " << v[i].r << ' ' << v[i].c << '\n';
            if(tc == v[i].c && tr == v[i].r)
            {
                v[i].t += 1;
            }
        }
                    //여기서 검사
        for(int i = 1; i<= 100; i++)
        {   
            for(int j = 1; j<= 100; j++)
            {
                if(m[i][j] >1)
                {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}