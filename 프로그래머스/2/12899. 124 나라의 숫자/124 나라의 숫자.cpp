#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";

    string b = "";
    while (n / 3 > 0)
    {
        b += n % 3 + '0';
        n /= 3;
    }
    b += n % 3 + '0';

    //cout << b << '\n';

    string otf = "";
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '0')
        {
            int ix = i+1;
            while (ix < b.length())
            {
                int nxt = b[ix] - '0';// 0인 자리의 다음 자리
                if (nxt == 0) //여기서 1을 당겨 써야하는데 얘가 1보다 작으면? 
                {
                    b[ix] = '2';
                }
                else
                {
                    b[ix] = b[ix] - 1;
                    otf += '4';
                    break;
                }
                ix++;
            }
        }
        else if (b[i] == '1')
        {
            otf += '1';
        }
        else
        {
            otf += '2';
        }

    }

    reverse(otf.begin(), otf.end());

    return otf;
}
