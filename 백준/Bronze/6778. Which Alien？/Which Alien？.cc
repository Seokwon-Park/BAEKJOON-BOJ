#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ant, eye;
    cin >> ant >> eye;

    if (ant >= 3 && eye <= 4)
        cout << "TroyMartian\n";
    if (ant <= 6 && eye >= 2)
        cout << "VladSaturnian\n";
    if (ant <= 2 && eye <= 3)
        cout << "GraemeMercurian\n";


    return 0;
}