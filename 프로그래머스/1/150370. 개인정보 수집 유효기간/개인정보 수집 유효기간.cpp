#include <bits/stdc++.h>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
    
    Date(string n)
    {
        year = stoi(n.substr(0,4));
        month = stoi(n.substr(5,2));
        day = stoi(n.substr(8, 2));
    }
    
    bool operator<(const Date& d)
    {
        if(this->year == d.year)
            if(this->month == d.month)
            {
                return this->day < d.day;
            }
            else
            {
                return this->month < d.month;
            }
        else
        {
            return this->year < d.year;
        }        
    }
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    Date tday(today);
    
    cout << tday.year << ' ' << tday.month << ' ' << tday.day;
    
    unordered_map<char, int> term;
    
    for(auto t:terms)
    {
        term[t[0]] = stoi(t.substr(2));
    }
    
    for(int i = 0; i< privacies.size(); i++)
    {
        string str= privacies[i];
        char termch = str[str.length()-1];
        string d = str.substr(0, 10);
        Date ymd(d);
        
        ymd.day--;
        if(ymd.day == 0)
        {
            ymd.day = 28;
            ymd.month--;            
            if(ymd.month == 0)
            {
                ymd.month = 12;
                ymd.year--;
            }
        }
        ymd.month += term[termch];
        if(ymd.month > 12)
        {            
            ymd.year += ymd.month / 12;
            ymd.month %= 12 ;
            if(ymd.month == 0) 
            {
                ymd.month = 12;
                ymd.year--;
            }
        }       
        
        if(ymd < tday)
        {
            answer.push_back(i+1);
        }
    }

    return answer;
}