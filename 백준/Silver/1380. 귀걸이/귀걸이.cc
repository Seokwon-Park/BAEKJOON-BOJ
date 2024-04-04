#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1;
	int n;
	while (1)
	{
		cin >> n;
		cin.ignore();
		if (n == 0)break;
		vector<string> v(n+1, "");
		vector<bool> chk(n + 1, 0); // true면 뺏긴거
		for (int i = 1; i <= n; i++)
		{
			getline(cin, v[i]);
		}
		for (int i = 1; i <= n*2-1; i++)
		{
			int ix;
			char ab;
			cin >> ix >> ab;
			chk[ix] = !chk[ix];
		}

		for (int i = 1; i <= n; i++)
		{
			if (chk[i])
			{
				cout << tc++ << ' ' << v[i] << '\n';
				break;
			}
		}
	}

	return 0;
}