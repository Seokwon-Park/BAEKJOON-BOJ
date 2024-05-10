#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int n = is_suffix.size();
    
    if(n > my_string.size()) return 0;
    for(int i = 0; i< n;i ++)
    {
        if(my_string[my_string.size()-i-1] != is_suffix[n-i-1])
            return 0;
    }
    return 1;
}