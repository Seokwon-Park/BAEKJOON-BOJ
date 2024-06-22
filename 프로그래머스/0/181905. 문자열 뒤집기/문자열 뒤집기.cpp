#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    
    while(s<e)
    {
        swap(my_string[s],my_string[e]);
        s++;
        e--;
    }
    
    return my_string;
}