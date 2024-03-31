#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isExist[7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int s;
		cin >> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int q, p;
			cin >> q >> p;
			s += q * p;
		}
		cout << s << '\n';
	}

	return 0;
}