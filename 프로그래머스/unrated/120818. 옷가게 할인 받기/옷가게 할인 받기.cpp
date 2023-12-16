#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    
    if(price >= 500000)
    {
        price = price*4/5;
    }
    else if( price >= 300000)
    {
        price = price*9/10;
    }
    else if(price >= 100000)
    {
        price = price*19/20;
    }          
    
    return price;
}