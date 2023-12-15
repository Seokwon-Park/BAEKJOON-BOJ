#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> stck;
    int count = 0;
    for(auto i: ingredient)
    {
        if(stck.empty()) stck.push_back(i);
        else
        {
            if(i == 1 )
            {
                if( stck.back() == 3)
                {
                    count++;
                }
                else
                {
                    count--;
                }
                stck.push_back(i);
            }
            else if(i == 2)
            {
                if(stck.back() == 1)
                {
                    count++;
                }
                else
                {
                    count--;
                }
                stck.push_back(i);
            }
            else if(i == 3)
            {
                if(stck.back() == 2)
                {
                    count++;
                }
                else
                {
                    count--;
                }
                stck.push_back(i);
            }
            if(count == 3)
            {
                for(int i =0 ;i < 4; i++)
                {
                    stck.pop_back();
                }
                answer++;
                count = 0;
            }
        }
    }
    return answer;
}