#include <string>
#include <vector>

using namespace std;

vector<int> failure(string s)
{
    int j = 0;
    vector<int> f(s.size(), 0);
    for(int i =1; i< s.size(); i++)
    {
        while(j>0 && s[i] !=s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int solution(string myString, string pat) {
    int answer = 0;
    
    vector<int> f = failure(pat);
    
    int j = 0;
    for(int i = 0; i< myString.size();i++)
    {
        while(j>0&& myString[i] != pat[j]) j = f[j-1];
        if(myString[i] == pat[j]) j++;
        if(j == pat.size())
        {
            answer++;
            i = i-j+1;
            j = 0;
        }
    }
    
    return answer;
}