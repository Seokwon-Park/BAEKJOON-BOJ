#include <bits/stdc++.h>

using namespace std;

int prefix[200005][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int tc;
    cin >> tc;
    
    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            prefix[i][j] = prefix[i-1][j];
        }
        prefix[i][str[i-1] - 'a']++;
    }


    for (int i = 0; i < tc; i++)
    {
        char c;
        int st;
        int ed;

        cin >> c >> st >> ed;

        cout << prefix[ed + 1][c - 'a'] - prefix[st][c - 'a'] << '\n';
    }


    return 0;
}