#include <string>
#include <vector>

using namespace std;

bool isUsed[100005];

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    int ix = 0;
    while(ix < arr.size() && answer.size() < k)
    {
        if(!isUsed[arr[ix]])
        {
            isUsed[arr[ix]] = true;
            answer.push_back(arr[ix]);
        }
        ix++;
    }
    while(answer.size() <k ) answer.push_back(-1);
    
    
    
    return answer;
}