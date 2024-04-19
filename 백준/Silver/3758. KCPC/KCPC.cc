#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		vector<vector<int>> score(n + 1, vector<int>(k + 1, 0));
		vector<int> lesssub(n + 1, 0);
		vector<int> lastsub(n + 1, -1);
		map<int, tuple<int,int,int>> mp;
		for (int i = 0; i < m; i++)
		{
			int id, j, s;
			cin >> id >> j >> s;
			score[id][j] = max(score[id][j], s);
			lesssub[id]++;
			lastsub[id] = i;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int sc, sub, ti;
				tie(sc, sub, ti) = mp[i];
				sc += score[i][j];
				sub = lesssub[i];
				ti = lastsub[i];
				mp[i] = tie(sc, sub, ti);
			}
		}
		vector<pair<int, tuple<int,int,int>>> v(mp.begin(), mp.end());

		sort(v.begin(), v.end(), [](const auto& a, const auto& b)
			{
				int as, asub, at;
				int bs, bsub, bt;
				tie(as, asub, at) = a.second;
				tie(bs, bsub, bt) = b.second;
				if (as == bs)
				{
					if (asub == bsub)
					{
						return at < bt;
					}
					return asub < bsub;
				}
				return as > bs;
			});

		for (int i = 0; i < n; i++)
		{
			if (v[i].first == t)
			{
				cout << i+1;
				break;
			}
		}
		cout << '\n';
	}

	return 0;
}
