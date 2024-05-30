#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    istringstream iss(binomial);
    string s;
    vector<string> res;
    while(getline(iss, s, ' '))
    {
        res.push_back(s);
    }
    
    int a= stoi(res[0]);
    int b = stoi(res[2]);
    if(res[1] == "+")
        answer = a+b;
    else if(res[1] == "-")
        answer = a-b;
    else
        answer = a*b;
    
    return answer;
}