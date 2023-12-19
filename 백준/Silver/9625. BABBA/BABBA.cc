#include <bits/stdc++.h>

using namespace std;

int dpA[50];
int dpB[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dpA[0] = 1;
    dpB[0] = 0;
    dpA[1] = 0;
    dpB[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dpA[i] = dpA[i - 1] + dpA[i - 2];
        dpB[i] = dpB[i - 1] + dpB[i - 2];
    }

    cout << dpA[n] << ' ' << dpB[n];


    return 0;
}