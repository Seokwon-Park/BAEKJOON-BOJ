#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Case #" << i << ": ";
		int rice = 0;
		for (int j = 0; j < 5; j++)
		{
			int m;
			cin >> m;
			if (m > rice)
				rice = m;
		}
		cout << rice << '\n';
	}

	return 0;
}