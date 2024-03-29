#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a, b;
	cin >> a >> b;
	double res = (a / 100.0) * (100.0 - b);
	if (res >= 100)
		cout << 0;
	else
		cout << 1;


	return 0;
}