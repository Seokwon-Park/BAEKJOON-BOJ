#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		double d, f, p;
		cin >> d >> f >> p;
		cout << fixed;
		cout.precision(2);
		cout << '$' << d * f * p << '\n';
	}


	return 0;
}