#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

pii v[4][200005];
bool isPrized[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		v[0][i] = { b, a };
		v[1][i] = { c, a };
		v[2][i] = { d, a };
		v[3][i] = { e, a };
	}

	for (int i = 0; i < 4; i++)
	{
		sort(v[i], v[i] + n, [](auto a, auto b)
			{
				if (a.first == b.first)
				{
					return a.second < b.second;
				}
				return a.first > b.first;
			}
		);
	}

	vector<int> ans;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!isPrized[v[i][j].second])
			{
				ans.push_back(v[i][j].second);
				isPrized[v[i][j].second] = true;
				break;
			}
		}
	}

	for (auto i : ans)
		cout << i << ' ';

	return 0;
}