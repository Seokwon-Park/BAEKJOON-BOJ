#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float a = (float)num1 / (float)num2;
    a*=1000;
    return a;
}