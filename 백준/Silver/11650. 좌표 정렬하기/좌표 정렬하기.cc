#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b)
        {  

            if (a.first == b.first)
            {
                return a.second < b.second;
            }

            return a.first < b.first;
        }
    );

    for (auto pair : p)
    {
        cout << pair.first << ' ' << pair.second << '\n';
    }

      

    return 0;
}