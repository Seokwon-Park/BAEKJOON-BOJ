#include <bits/stdc++.h>

using namespace std;

string toLower(string& str)
{
    for(auto& c: str)
    {
        if(!isalpha(c))continue;
            c = tolower(c);
    }
    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    multiset<string> m1;
    multiset<string> m2;
    
    str1 = toLower(str1);
    str2 = toLower(str2);
    
    for(int i =0; i< str1.length()-1; i++)
    {
        if(isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            string sub = str1.substr(i, 2);
            m1.insert(sub);
        }
    }
    
    for(int i =0; i< str2.length()-1; i++)
    {
        if(isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            string sub = str2.substr(i, 2);
            m2.insert(sub);
        }
    }

    vector<string> sum(m1.size()+ m2.size());
    vector<string> intersect(min(m1.size(), m2.size()));
    
    auto it = set_union(m1.begin(), m1.end(), m2.begin(), m2.end(), sum.begin());
    sum.resize(it - sum.begin());
    
    it = set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(), intersect.begin());
    intersect.resize(it - intersect.begin());
    
    if(m1.empty() && m2.empty()) return 65536;
        
    float a = sum.size();
    float b = intersect.size();
    
    answer = b/a*65536;
    

    return answer;
}