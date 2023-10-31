#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown+yellow;
    
    for(int i =1; i<= yellow; i++)
    {
        if(yellow %i != 0) continue;
        int j = yellow / i;
        if((i+2)*(j+2) == total)
        {
            answer.push_back(j+2);
            answer.push_back(i+2);
            break;
        }
        
    }
    
    return answer;
}