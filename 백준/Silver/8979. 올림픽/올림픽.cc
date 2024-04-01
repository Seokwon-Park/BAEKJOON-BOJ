#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int gp, sp, bp;
	vector<pair<int, tuple<int, int, int>>> medal;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		medal.push_back({ a, tie(b,c,d) });
		if (a == k)
		{
			tie(gp, sp, bp) = tie(b, c, d);
		}
	}

	sort(medal.begin(), medal.end(), [](auto& a, auto& b)
		{
			int g1, s1, b1;
			int g2, s2, b2;
			tie(g1, s1, b1) = a.second;
			tie(g2, s2, b2) = b.second;
			if (g1 == g2)
			{
				if (s1 == s2)
				{
					return b1 > b2;
				}
				return s1 > s2;
			}
			return g1 > g2;
		});

	int rank = 1;
	for (auto [num, tup] : medal)
	{
		int g, s, b;
		tie(g, s, b) = tup;
		if (g == gp && s == sp && b == bp)
		{
			cout << rank;
			break;
		}
		rank++;
	}


	return 0;
}
