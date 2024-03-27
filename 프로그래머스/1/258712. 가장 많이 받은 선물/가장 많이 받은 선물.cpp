#include <bits/stdc++.h>

using namespace std;

vector<string> split(string& s)
{
    istringstream iss(s);
    string tmp;
    vector<string> ret;
    while(getline(iss, tmp, ' '))
    {
        ret.push_back(tmp);
    }
    return ret;
}

int solution(vector<string> f, vector<string> gifts) {
    int answer = 0;
    int n = f.size();
    map<string, map<string, int>> m; // from, to
    map<string, int> giftn;
    map<string, int> giftget;
    
    for(string s:gifts)
    {
        vector<string> v = split(s);
        m[v[0]][v[1]]++;
        giftn[v[0]]++;
        giftn[v[1]]--;
    }
    
    /*for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            cout << m[f[i]][f[j]] << ' ';
        }
        cout << '\n';
    }*/

    
    for(int i = 0; i< n; i++)
    {
        for(int j = i; j< n; j++)
        {
            if(i == j)continue;
            if((m[f[i]][f[j]] == 0 && m[f[j]][f[i]] == 0)
               || (m[f[i]][f[j]] == m[f[j]][f[i]]))
            {
                if(giftn[f[i]] > giftn[f[j]])
                    giftget[f[i]]++;
                else if(giftn[f[i]] < giftn[f[j]])
                    giftget[f[j]]++;
            }
            else
            {
                 if(m[f[i]][f[j]] > m[f[j]][f[i]])
                    giftget[f[i]]++;
                 else if(m[f[i]][f[j]] < m[f[j]][f[i]])
                    giftget[f[j]]++;
            }
        }
    }
    
    /*for(auto [x, y]:giftn)
    {
        cout << x << ' ' << y << '\n';
    }*/
    
    for(auto [x, y]:giftget)
    {
       answer = max(answer, y);
    }
    
    
    return answer;
}