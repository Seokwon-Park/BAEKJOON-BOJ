#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

map<int, map<int, bool>> isPoint;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
		isPoint[x][y] = true;
	}
	sort(v.begin(), v.end());

	vector<vector<pii>> xAxis;

	for (int i = 0; i < n; i++)
	{
		auto [x, y] = v[i];
		if (xAxis.empty())
		{
			xAxis.push_back({ make_pair(x,y) });
		}
		else
		{
			if(xAxis.back()[0].first == x)
				xAxis.back().push_back(make_pair(x,y));
			else
				xAxis.push_back({ make_pair(x,y) });
		}
	}

	int ans = 0;
	for (int i = 0; i < xAxis.size(); i++)
	{
		for (int j = i + 1; j < xAxis.size(); j++)
		{
			int x1 = xAxis[i][0].first;
			int x2 = xAxis[j][0].first;
			for (int a = 0; a < xAxis[i].size(); a++)
			{
				for (int b = a+1; b < xAxis[i].size(); b++)
				{
					int y1 = xAxis[i][a].second;
					int y2 = xAxis[i][b].second;
					if (isPoint[x1][y1] && isPoint[x1][y2] && isPoint[x2][y1] && isPoint[x2][y2])
						ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}