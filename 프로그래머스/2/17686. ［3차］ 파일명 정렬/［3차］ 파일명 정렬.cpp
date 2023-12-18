#include <bits/stdc++.h>

using namespace std;

struct Format
{
    string head = "";
    string number = "";
    
    Format(string str)
    {
        int head_ix = 0;
        for(int i =0; i< str.length(); i++)
        {
            if(!isdigit(str[i]))
                head+= tolower(str[i]);
            else
            {
                head_ix = i;
                break;
            }
        }
        for(int i = head_ix; i<str.length(); i++)
        {
            if(isdigit(str[i]))
                number += str[i];
            else
                break;
        }
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(auto str:files)
    {
        Format f(str);
        //cout << f.head << ' ' << f.number <<'\n';
    }
    
    stable_sort(files.begin(), files.end(), [](string a, string b){
        Format A(a);
        Format B(b);
        if(A.head == B.head)
        {
            return stoi(A.number)<stoi(B.number);
        }
        return A.head < B.head;
    });
    return files;
}