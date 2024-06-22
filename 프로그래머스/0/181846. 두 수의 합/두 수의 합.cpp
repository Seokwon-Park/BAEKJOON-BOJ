#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    
    int n = max(a.size(),b.size());
    a = string(n-a.size(), '0') + a;
    b = string(n-b.size(), '0') +b;
    int carry =0;
    string ans(n, '0');
    for(int i = n-1; i>=0; i--)
    {
        int aa = a[i]-'0';
        int bb = b[i]-'0';
        int res = (aa +bb+carry)%10;
        carry = (aa+bb+carry)/10;
        ans[i] = res+'0';
    }
    if(carry)
        ans = '1'+ans;
    
    return ans;
}