#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

char b[105][105];
char bb[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		int n = sqrt(s.size());

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bb[i][j] = s[i * n + j];
			}
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[n-1-j][i] = bb[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << b[i][j];
			}
		}
		cout << '\n';
	}

	return 0;
}