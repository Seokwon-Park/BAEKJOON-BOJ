#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    answer = s;
    sort(answer.rbegin(), answer.rend());
    return answer;
}