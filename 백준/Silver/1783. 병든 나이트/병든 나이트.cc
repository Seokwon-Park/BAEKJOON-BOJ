#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	else if (n == 2)
	{
		cout << min(4, (m + 1) / 2);
		return 0;
	}
	else
	{
		if (m >= 7)
		{
			cout << m - 7 + 5;
			return 0;
		}
		else
		{
			cout << min(4,m);
			return 0;
		}
	}

	return 0;
}