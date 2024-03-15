#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int c = b - a;

    if (c <= 0)
    {
        cout << "Congratulations, you are within the speed limit!";
    }
    else if (c <= 20)
    {
        cout << "You are speeding and your fine is $100.";
    }
    else if (c <= 30)
    {
        cout << "You are speeding and your fine is $270.";
    }
    else
    {
        cout << "You are speeding and your fine is $500.";

    }

    return 0;
}
