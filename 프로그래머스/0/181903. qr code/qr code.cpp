#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    int st = r;
    while( st< code.size())
    {
        answer += code[st];
        st+=q;
    }
    
    return answer;
}