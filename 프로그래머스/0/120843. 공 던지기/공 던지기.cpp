#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    int st = 1;
    int cur = 0;
    while(st < k)
    {
        cur = (cur+2)%numbers.size();
        answer = numbers[cur];
        st++;
    }
    
    return answer;
}