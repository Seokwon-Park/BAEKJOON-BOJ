#include <string>
#include <vector>

using namespace std;

int sum;
bool indexUsed[15];
int answer;
vector<int> ns;

void find(int m)
{
    if(m == 3)
    {
        if(sum == 0)
        {
            answer++;
        }
        return;
    }
    for(int i = 0; i< ns.size(); i++)
    {
        if(!indexUsed[i])
        {
            indexUsed[i] = true;
            sum += ns[i];
            find(m+1);
            sum -= ns[i];
            indexUsed[i] = false;
        }
    }
}

int solution(vector<int> number) {
    
    
    ns = number;
    
    find(0);
    
    return answer/6;
}