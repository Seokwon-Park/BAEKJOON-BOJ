#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(auto& c: my_string)
    {
        c = tolower(c);
    }
    
    sort(my_string.begin(),my_string.end());
    
    return my_string;
}