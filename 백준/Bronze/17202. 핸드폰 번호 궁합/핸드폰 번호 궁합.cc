#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a;
    string b;

    cin >> a >> b;

    string ab;
    for (int i = 0; i < 8; i++)
    {
        ab += a[i];
        ab += b[i];
    }


    while (ab.length() != 2)
    {
        string tmp = "";
        for (int i = 0; i < ab.length() - 1; i++)
        {
            int a = ab[i] - '0';
            int b = ab[i + 1] - '0';
            char c = ((a + b) % 10) + '0';
            tmp += c;
        }
        ab = tmp;
    }
    
    cout << ab;

    return 0;
}