#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    
    vector<int> bf(26, 0);
    for(auto c : before)
        bf[c-'a'] ++;
    
    for(auto c: after)
    {
        bf[c-'a']--;
        if(bf[c-'a'] <0)
            return 0;
    }
    
    
    return 1;
}