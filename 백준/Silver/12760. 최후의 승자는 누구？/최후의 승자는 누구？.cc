#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[105][105];
int score[105];

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
		sort(b[i], b[i] + m, greater<int>());
	}

	for (int i = 0; i < m; i++)
	{
		int mx = 0;
		for (int j = 0; j < n; j++)
		{
			mx = max(mx, b[j][i]);
		}

		for (int j = 0; j < n; j++)
		{
			if (mx == b[j][i])
			{
				score[j]++;
			}
		}
	}

	int mxs = *max_element(score, score + n);
	for (int i = 0; i < n; i++)
	{
		if (score[i] == mxs)
			cout << i+1 << ' ';
	}

	return 0;
}