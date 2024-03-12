#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool isS = true;
	for (int i = 0; i < 8; i++)
	{
		int n;
		cin >> n;
		if (n != 0 && n != 1)
		{
			isS = false;
		}
	}
	cout << (isS ? 'S' : 'F');

	return 0;
}