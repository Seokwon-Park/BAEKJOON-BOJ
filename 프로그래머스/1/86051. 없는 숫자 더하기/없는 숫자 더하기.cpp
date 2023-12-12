#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> chk(10, true);
    
    for(int n :numbers)
    {
        chk[n] = false;
    }
    
    for(int i = 0; i< 10; i++)
    {
        if(chk[i]) answer += i;
    }
    return answer;
}