#include <string>
#include <vector>

using namespace std;

bool isused1[12];
bool isused2[25];
bool isused3[25];

int nn;
int ans;

void func(int row)
{
    if(row == nn)
    {
        ans++;
        return;
    }
    for(int i = 0; i < nn ;i ++)
    {
        if(isused1[i] || isused2[row+i] || isused3[nn+row-i-1]) continue;  
        isused1[i] = true;
        isused2[row+i] = true ;
        isused3[nn+row-i-1] = true;
        func(row+1);
        isused1[i] = false;
        isused2[row+i] = false;
        isused3[nn+row-i-1] = false;
    }
}

int solution(int n) {
    int answer = 0;
    
    nn = n;
    
    func(0);
    
    return ans;
}