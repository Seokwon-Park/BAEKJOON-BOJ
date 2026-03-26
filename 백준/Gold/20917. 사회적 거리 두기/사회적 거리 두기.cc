#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, s;
int x[200005];

int solve(int mid)
{
	int prev = x[0];
	int selected = 1;
	for (int i = 1; i < n; i++)
	{
		if (x[i] - prev >= mid)
		{
			selected++;
			prev = x[i];
			if (selected == s)
			{
				return true;
			}
		}
	}

	return selected >= s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> s;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}

		sort(x, x + n);

		int st = 0;
		int en = 1e9 + 1;
		while (st + 1 < en)
		{
			int mid = (st + en) / 2;
			if (solve(mid))
			{
				st = mid;
			}
			else
			{
				en = mid;
			}
		}
		cout << st <<'\n';
	}

	return 0;
}