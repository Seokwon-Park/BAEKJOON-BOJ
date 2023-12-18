#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    unordered_map<string, bool> m;
    unordered_map<char, pair<int,int>> cmd;
    
    //x, y
    cmd['U'] = {0,1};
    cmd['D'] = {0,-1};
    cmd['L'] = {-1,0};
    cmd['R'] = {1,0};
    
    int sx = 0, sy = 0;
    for(auto c:dirs)
    {
        int tx = sx+cmd[c].first; 
        int ty = sy+cmd[c].second;
        if(tx > 5 || ty > 5 || tx < -5 || ty < -5) continue;
        char revc;
        switch(c)
        {
            case 'U':
                revc= 'D';
                break;
            case 'D':
                revc= 'U';
                break;
            case 'L':
                revc= 'R';
                break;
            case 'R':
                revc= 'L';
                break;
                
        }
        string key = to_string(sx) + to_string(sy);
        key+=c;
        string revkey = to_string(tx) + to_string(ty);
        revkey += revc;
        if(m[revkey] != true)
        {
            answer++;
            m[revkey] = true;
        }
        m[key] = true;
        sx = tx;
        sy = ty;
    }
    
    for(auto a:m)
    {
        cout<<boolalpha;
        cout << a.first << '-'<< a.second << '\n';
    }
    
    
    return answer;
}