#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> map;
    
    for(int i =0 ; i< name.size(); i++)
    {
        map.insert(make_pair(name[i], yearning[i]));
    }
    
    
    for(auto p:photo)
    {   
        int ans = 0;
        for(auto n:p)
        {
            ans += map[n];
        }
        answer.push_back(ans);
    }
    
     

    return answer;
}
