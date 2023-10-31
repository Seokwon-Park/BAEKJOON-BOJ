#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Counter(int n)
{
    int count = 0;
    int tmp = n;
    while(tmp != 0)
    {
        if(tmp % 2 == 1)
        {
            count++;
        }
        tmp /= 2;                    
    }

    return count;
}

int solution(int n) {
    int answer = 0;
    
    int origin = Counter(n);
    int other = n;
    while(true)
    {
        int tmp = Counter(++other);
        if(tmp == origin)
        {
            answer = other;
            break;
        }
    }
    
    return answer;
}