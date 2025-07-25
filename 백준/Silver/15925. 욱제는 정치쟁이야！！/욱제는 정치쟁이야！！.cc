#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int b[32][32];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> rowval(n);
	vector<int> colval(n);
	int left = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 1)
			{
				rowval[i] |= 1 << j;
				colval[j] |= 1 << i;
				left++;
			}
		}
	}

	if (k == 1)
	{
		left = n * n - left;
	}

	while (left)
	{
		bool changed = false;
		for (int i = 0; i < n; i++)
		{
			if (k == 1 && rowval[i] == (1 << n) - 1) continue;
			if (k == 0 && rowval[i] == 0) continue;
			int one = __builtin_popcount(rowval[i]);
			if (k == 1)
			{
				if (one > n / 2)
				{
					changed = true;
					rowval[i] = (1 << n) - 1;
					left -= n - one;
					for (int l = 0; l < n; l++)
					{
						colval[l] |= 1 << i;
					}
				}
			}
			else if (k == 0)
			{
				if (n - one > n / 2)
				{
					changed = true;
					rowval[i] = 0;
					left -= one;
					for (int l = 0; l < n; l++)
					{
						colval[l] &= ~(1 << i);
					}
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (k == 1 && colval[i] == (1 << n) - 1) continue;
			if (k == 0 && colval[i] == 0) continue;
			int one = __builtin_popcount(colval[i]);
			if (k == 1)
			{
				if (one > n / 2)
				{
					changed = true;
					colval[i] = (1 << n) - 1;
					left -= n - one;
					for (int l = 0; l < n; l++)
					{
						rowval[l] |= 1 << i;
					}
				}
			}
			else if (k == 0)
			{
				if (n - one > n / 2)
				{
					changed = true;
					colval[i] = 0;
					left -= one;
					for (int l = 0; l < n; l++)
					{
						rowval[l] &= ~(1 << i);
					}
				}
			}
		}
		if (changed == false)
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}