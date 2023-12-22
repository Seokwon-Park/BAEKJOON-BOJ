#include <bits/stdc++.h>

using namespace std;

string sound[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
unordered_map<string,char> um;

string makesong(string song, int period)
{
    string new_song = "";
    for(int i =0 ;i < period; i++)
    {
        new_song+= song[i%song.length()];
    }
    return new_song;
}

string convert(string str)
{
    string res = "";
    for(int i=0; i< str.length(); i++)
    {
        string tmp = "";
        if(i < str.length()-1 && str[i+1] == '#')
        {
            tmp = str.substr(i,2);
            res += um[tmp];
            i++;
        }
        else
        {
            tmp += str[i];
            res += um[tmp];
        }
    }
    return res;
}

int calc_time(string st, string ed)
{
    int shour = stoi(st.substr(0,2));
    int smin = stoi(st.substr(3,2));
    int ehour = stoi(ed.substr(0,2));
    int emin = stoi(ed.substr(3,2));
    return (ehour-shour)*60 + (emin-smin);
}

vector<string> split(string str)
{
    vector<string> res;
    istringstream iss(str);
    string tmp;
    
    while(getline(iss,tmp, ','))
    {
        res.push_back(tmp);
    }
    
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    for(int i = 0; i< 12; i++)
    {
        um[sound[i]] = 'a'+i;
    }
    
    bool isFind = false;
    vector<pair<string,int>> list;
    for(auto music:musicinfos)
    {
        vector<string> info = split(music);
        int period = calc_time(info[0], info[1]);
        string conv = convert(info[3]);
        string findmusic = convert(m);
        
        string song = makesong(conv, period);
        
        if(song.find(findmusic) != -1)
        {
            list.push_back({info[2],period});
            isFind = true;
        }
    }
    
    stable_sort(list.begin(), list.end(), [](pair<string,int> a, pair<string,int> b)
         {
             return a.second>b.second;
        });
    
    if(isFind)
    {
        answer = list[0].first;
    }
    else
    {
        answer = "(None)";
    }
        
    
    return answer;
}