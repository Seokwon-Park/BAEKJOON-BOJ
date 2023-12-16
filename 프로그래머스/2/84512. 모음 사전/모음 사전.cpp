#include <bits/stdc++.h>

using namespace std;

bool used[5][5];
string dict ="";
string str = "AEIOU";
string findword;
int cnt = 0;
int answer;

void func(int k)
{
    if(k == 4)
    {
        for(int i = 0; i< 5; i++)
        {
            dict += str[i];   
            cnt++;
            if(dict == findword) 
            {
                answer = cnt;
                dict.pop_back(); 
                return;
            }
            //cout << dict<< ' ' << cnt << '\n';            
            dict.pop_back();   
        }
        return;
    }
    
    for(int i = 0; i< 5; i++)
    {
        dict.push_back(str[i]); 
        cnt++;
        if(dict == findword) 
        {
            answer = cnt;
            dict.pop_back(); 
            return;
        }
        //cout << dict << ' ' << cnt << '\n';
        func(k+1);
        dict.pop_back();        
    }
}

int solution(string word) {
      
    
    findword = word;
    func(0);

    return answer;
}