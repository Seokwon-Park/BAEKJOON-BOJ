#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string dir) {
    vector<int> answer;
    
    if(dir == "right")
    {
        answer.push_back(*(numbers.end()-1));
        for(int i = 0; i< numbers.size()-1;i++)
        {
            answer.push_back(numbers[i]);
        }
    }
    else
    {
        for(int i = 1; i< numbers.size();i++)
        {
            answer.push_back(numbers[i]);
        }
        answer.push_back(*numbers.begin());
    }
    
    return answer;
}