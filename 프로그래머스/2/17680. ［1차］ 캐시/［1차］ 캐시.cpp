#include <bits/stdc++.h>

using namespace std;

std::string toUpper(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(c);
    }
    return result;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

    vector<string> cache;
    
    if(cacheSize == 0) answer= cities.size() * 5;
    else
    for(auto& city: cities)
    {
        city = toUpper(city);
        auto res = find(cache.begin(), cache.end(), city);
        if(res == cache.end())
        {
            if(cache.size() == cacheSize)
            {
                cache.erase(cache.begin());
            }
            cache.push_back(city);
            answer+=5;
        }
        else
        {
            cache.erase(res);
            answer+=1;   
            cache.push_back(city);
        }
    }
    




	return answer;
}