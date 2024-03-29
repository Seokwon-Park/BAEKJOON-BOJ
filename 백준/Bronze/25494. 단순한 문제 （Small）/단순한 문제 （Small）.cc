#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int x = 1; x <= a; x++)
			for (int y = 1; y <= b; y++)
				for (int z = 1; z <= c; z++)
				{
					int xmy = x % y;
					int ymz = y % z;
					int zmx = z % x;
					if (xmy == ymz && ymz == zmx)
						ans++;
				}

		cout << ans << '\n';
	}

	return 0;
}