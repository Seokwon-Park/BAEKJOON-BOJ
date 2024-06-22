#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int st = 6;
    while(st %n != 0)
    {
        st+= 6;
        answer++;
    }
    
    return answer;
}