#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool canEscape = true;
		for (int j = 0; j < n; j++)
		{
			if (b[j][i] == 'O')
			{
				canEscape = false;
				break;
			}
		}
		if (canEscape)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << "ESCAPE FAILED";

	return 0;
}