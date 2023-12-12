#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int l = s.length();
    int mid = l/2;
    if(l % 2 ==1)
    {
        answer = s[l/2];
    }
    else
    {
        answer = s.substr(mid-1, 2);
    }
    return answer;
}