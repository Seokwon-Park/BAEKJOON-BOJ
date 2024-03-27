#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    for(char c:rsp)
    {
        char k;
        if(c == '2')
            k = '0';
        else if( c== '0')
            k ='5';
        else
            k = '2';
        answer+=k;
    }
    return answer;
}