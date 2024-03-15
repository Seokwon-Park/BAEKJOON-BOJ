#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vi v(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
    }

    bool isRDB[3] = { true, true, true };


    for (int i = 0; i < 3; i++)
    {
        if (v[i] >= v[i + 1])
        {
            isRDB[0] = false;
        }
        if (v[i] <= v[i + 1])
        {
            isRDB[1] = false;
        }
        if (v[i] != v[i + 1])
        {
            isRDB[2] = false;
        }
    }

    int br = count(isRDB, isRDB + 3, true);
    if (br == 1)
    {
        if (isRDB[0])
            cout << "Fish Rising";
        else if (isRDB[1])
            cout << "Fish Diving";
        else
            cout << "Fish At Constant Depth";
    }
    else
    {
        cout << "No Fish";
    }



    return 0;
}
