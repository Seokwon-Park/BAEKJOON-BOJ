#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<double, double>> xy;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		xy.push_back({ x,y });
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		int prev;
		cin >> prev;
		double res = 0.0;
		for (int j = 0; j < p-1; j++)
		{
			int cur;
			cin >> cur;
			double x = (xy[cur].first - xy[prev].first);
			double y = (xy[cur].second - xy[prev].second);
			res += sqrt(x * x + y * y);
			prev = cur;
		}
		cout << (int)round(res) << '\n';
	}

	return 0;
}