#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		ll m;
		cin >> m;
		bool isBig = true;
		for (int i = 2; i <= 1e6; i++)
		{
			if (m % i == 0)
			{
				isBig = false;
				break;
			}
		}
		if (isBig)
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}