#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (m == 300)
			cout << 1;
		else if (m >= 275)
			cout << 2;
		else if (m >= 250)
			cout << 3;
		else
			cout << 4;
		cout << ' ';
	}

	return 0;
}