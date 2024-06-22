#include <string>
#include <vector>

using namespace std;

bool is3X[1000];

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i<1000; i++)
    {
        if(i%3 == 0)
            is3X[i] = true;
        int tmp = i;
        while(tmp)
        {
            if(tmp%10 ==3)
            {
                is3X[i] = true;
                break;
            }
            tmp/=10;
        }
    }

    int ix =1;
    for(int i = 1; i<=n; i++)
    {
        while(is3X[ix]) ix++;
        ix++;
    }
    
    return ix-1;
}