#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.size();
    string s(n, 'A');
    int cur = 0;
    int ans = 0;
    vector<int> v;
    for(int i =0; i<n; i++)
    {
        if(s[i] != name[i])
        {
            int next = name[i] -'A';
            int prev = 26-(name[i] -'A');
            ans += min(next, prev);
            v.push_back(i);
        }
    }
    
    if(v.empty()) return ans;
    int minDist = min(v[v.size()-1], (int)s.size() - v[0]);
    for(int i = 0; i< v.size()-1; i++)
    {
        int next = v[i];
        int prev = v[i+1];
        int nxtd = v[i];
        int pred = s.size()-v[i+1];
        if(nxtd > pred)
        {
            minDist = min(minDist, pred*2 + nxtd);
        }
        else
        {
            minDist = min(minDist, pred + nxtd*2);
        }
    }
    ans +=minDist;
    
    return ans;
}