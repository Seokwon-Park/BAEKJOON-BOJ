#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(auto q:queries)
    {
        int s= q[0];
        int e = q[1];
        int k = q[2];
        int res = INT_MAX;
        for(int i = s; i<=e; i++)
        {
            if(arr[i]>k)
            {
                res = min(res, arr[i]);
            }
        }
        if(res == INT_MAX)
            answer.push_back(-1);
        else
            answer.push_back(res);
    }
    
    return answer;
}