#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    
    if(dot[0] > 0)
    {
        if(dot[0]*dot[1]> 0)
        {
            answer=1;
        }
        else
        {
            answer =4;
        }
    }
    else
    {
        if(dot[0]*dot[1]> 0)
        {
            answer=3;
        }
        else
        {
            answer =2;
        }
    }
    
    return answer;
}