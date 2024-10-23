#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char b[105][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n, n)
	{
		string s;
		cin >> s;
		int cur = 0;
		for (int i = 0; i < s.size() / n; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < n; j++)
				{
					b[i][j] = s[cur++];
				}
			}
			else
			{
				for (int j = n - 1; j >= 0; j--)
				{
					b[i][j] = s[cur++];
				}
			}
		}

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < s.size() / n; i++)
			{
				cout << b[i][j];
			}
		}
		cout << '\n';
	}


	return 0;
}