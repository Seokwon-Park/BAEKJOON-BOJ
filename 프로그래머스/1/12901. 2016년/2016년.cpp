#include <string>
#include <vector>

using namespace std;

int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string Days[7] = {"FRI","SAT", "SUN","MON","TUE","WED","THU"};

string solution(int a, int b) {
    string answer = "";
    
    int sum = 0;
    for(int i = 0; i < a-1; i++)
    {
        sum += months[i];
    }
    sum+=(b-1);
    
    answer = Days[sum %7];
    
    
    
    return answer;
}