#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int hours[4] = { 4,6,4,10 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	map<string, int> work;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				string s;
				cin >> s;
				if (s == "-")
					continue;
				work[s] += hours[j];
			}
		}
	}

	int mn = INF;
	int mx = 0;
	for (auto [str, tt] : work)
	{
		mn = min(mn, tt);
		mx = max(mx, tt);
	}

	cout << (mx - mn <= 12 ? "Yes" : "No");

	return 0;
}