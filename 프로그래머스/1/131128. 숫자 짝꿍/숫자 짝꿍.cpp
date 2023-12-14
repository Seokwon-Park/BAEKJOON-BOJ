#include <bits/stdc++.h>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());

    std::string Z;

    std::set_intersection(X.begin(), X.end(), Y.begin(), Y.end(),
                          std::back_inserter(Z));
    
    if(Z.length() == 0) return "-1";
       
    sort(Z.begin(), Z.end(), [](char a, char b){return a> b;});
    
    if(count(Z.begin(), Z.end(), '0') == Z.length()) return "0";
        
    return Z;
}