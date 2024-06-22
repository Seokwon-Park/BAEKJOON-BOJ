#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    sort(numlist.begin(), numlist.end(), [n](int a, int b)
         {
             int adiff =abs(n-a);
             int bdiff =abs(n -b);
             
             if(adiff== bdiff)
             {
                 return a>b;
             }
             return adiff<bdiff;
         });
    
    return numlist;
}