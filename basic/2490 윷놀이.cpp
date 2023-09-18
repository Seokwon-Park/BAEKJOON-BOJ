#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
    {
        char ret = 'A';
        int countz = 0;
        for (int j = 0; j < 4; j++)
        {
            int input;
            cin >> input;
            if (input == 0)
                countz++;
            
                
        }
        if (countz == 0)
            cout << (char)(ret + 4) << '\n';
        else
            cout << (char)(ret +countz- 1) << '\n';
    }
    return 0;
}
