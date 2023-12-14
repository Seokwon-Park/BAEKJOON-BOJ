#include <bits/stdc++.h>

using namespace std;

void toLower(string& str)
{
    for(char& c: str)
    {
        if(isalpha(c))
        {
            c = tolower(c);
        }
    }
}

void rgx(string& str)
{
    string new_str = "";
    for(char c: str)
    {
        if(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.')
            new_str+=c;
    }
    str = new_str;
}

string solution(string new_id) {
    string answer = "";
    
    toLower(new_id);
    //cout << new_id << '\n';
    rgx(new_id);
    //cout << new_id << '\n';
    
    string new_str = "";
    bool dot = false;
    for(char c: new_id)
    {
        if(c == '.')
        {
            if(!dot) new_str+= c;
            dot = true;
        }
        else
        {
            new_str+= c;
            dot = false;
        }
    }
    //cout << new_str << '\n';
    
    int st = 0;
    if(new_str[st] == '.')
        new_str.erase(new_str.begin()+st);
    int ed = new_str.length() -1;
    if(new_str[ed] == '.')
        new_str.erase(new_str.begin()+ed);
    //cout << new_str << '\n';
    
    if(new_str.length() == 0)
        new_str.push_back('a');
    
    if(new_str.length() >= 16)
    {
        new_str = new_str.substr(0,15);
        ed = new_str.length() -1;
    }
    if(new_str[ed] == '.')
        new_str.erase(new_str.begin()+ed);
    
    ed = new_str.length() -1;
    char ch = new_str[ed];
    while(new_str.length() <= 2)
    {
        new_str.push_back(ch);
    }
    
    //cout << new_str;

    
    return new_str;
}