#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for(int i = 0 ; i< strArr.size(); i++)
    {
        for(auto& c: strArr[i])
        {
            if(i%2 == 0)
                c = tolower(c);
            else
                c = toupper(c);
        }
        answer.push_back(strArr[i]);
    }
    
    return answer;
}