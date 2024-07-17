#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    vector<int> pick(4, 0);
    fill(pick.begin(), pick.begin()+2, 1);
    do
    {
        vector<vector<int>> line1;
        vector<vector<int>> line2;
        for(int i = 0; i<4;i ++)
        {
            if(pick[i])
            {
                line1.push_back(dots[i]);
            }
            else
            {
                line2.push_back(dots[i]);
            }
        }
        int adx = line1[0][0] - line1[1][0];
        int ady = line1[0][1] - line1[1][1];
        int bdx = line2[0][0] - line2[1][0];
        int bdy = line2[0][1] - line2[1][1];
        int agcd = gcd(adx,ady);
        int bgcd = gcd(bdx,bdy);
        adx /= agcd;
        ady /= agcd;
        bdx /= bgcd;
        bdy /= bgcd;
        if(adx == bdx && ady == bdy && (adx * ady) * (bdx*bdy) >= 0)
            return 1;
    }while(prev_permutation(pick.begin(),pick.end()));
    
    return answer;
}