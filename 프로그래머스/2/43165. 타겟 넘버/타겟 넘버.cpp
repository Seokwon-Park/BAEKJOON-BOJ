#include <string>
#include <vector>

using namespace std;

vector<int> vec;
int sum = 0;
int answer;
int t;

void func(int ix)
{    
    if(ix == vec.size())
    {
        if(t == sum)
            answer++;
        return;
    }
    sum += vec[ix];
    func(ix+1);
    sum -= vec[ix];
    
    sum -= vec[ix];
    func(ix+1);
    sum += vec[ix];
}

int solution(vector<int> numbers, int target) {
    vec = numbers;    
    t = target;
    
    func(0);
    
    return answer;
}