#include <string>
#include <vector>

using namespace std;

vector<int> fail(string s)
{
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++)
    {
        while(j> 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int solution(string myString, string pat) {
    int answer = 0;
    
    for(auto& c: myString)
    {
        if(c == 'A') c= 'B';
        else c = 'A';
    }
    
    vector<int> f = fail(pat);
    
    int j = 0;
    for(int i = 0; i< myString.size(); i++)
    {
        while(j > 0 && myString[i] != pat[j]) j = f[j-1];
        if(myString[i] == pat[j]) j++;
        if(j == pat.size())
        {
            return 1;
        }
    }
    
    return answer;
}