#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int bg =INT_MAX, cc = INT_MAX;
	for (int i = 0; i < 3; i++)
	{
		int burg;
		cin >> burg;
		bg = min(bg, burg);

	}

	for (int i = 0; i < 2; i++)
	{
		int coci;
		cin >> coci;
		cc = min(cc, coci);
	}

	cout << bg + cc-50;

	return 0;
}