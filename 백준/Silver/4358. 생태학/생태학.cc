#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    map<string, int> m;
    int total = 0;

    while (getline(cin, str))
    {
        total++;
        m[str]++;
    }

    for (auto mp : m)
    {
        cout << fixed;
        cout.precision(4);
        cout << mp.first << ' ' << (float)mp.second/(float)total*100.f << '\n';
    }    

    return 0;
}