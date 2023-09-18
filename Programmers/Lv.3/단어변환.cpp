#include <bits/stdc++.h>

using namespace std;

bool is_linked(string a, string b)
{
    int diff_count = 0;
    for(int i = 0; i< a.length(); i++)
    {
        if (a[i] != b[i])
            diff_count++;
       // cout << a[i] << " " << b[i] << endl;
    }
    if(diff_count == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    //vector<int> times(words.size(), 0);
    vector<bool> used(words.size(), false);
    
    queue<pair<string, int>> Q;
    Q.push(make_pair(begin, 0));
    
    int move = 0;
    
    while(!Q.empty())
    {
        pair<string,int> str = Q.front();

        Q.pop();
        for(int i =0 ;i< words.size(); i++)
        {
            if(is_linked(str.first, words[i]) && !used[i])
            {
                if(words[i] == target) 
                {
                    answer = str.second+1;
                    break;
                }
                //cout << str.first <<" is linked with " << words[i] << endl;
                Q.push(make_pair(words[i], str.second+1));            
                words[i] = true;
            }            
        }        
    }    
    
    return answer;
}
