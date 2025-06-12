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

	sort(xy.begin(), xy.end());

	vector<double> xv(n), yv(n);
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = xy[i];
		xv[i] = x;
		yv[i] = y;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		double k;
		cin >> k;
		int ix = lower_bound(xv.begin(), xv.end(), k) - xv.begin();
		if (xv[ix] == k)
		{
			cout << 0;
		}
		else
		{
			if (yv[ix - 1] < yv[ix])
			{
				cout << 1;
			}
			else if (yv[ix - 1] == yv[ix])
			{
				cout << 0;
			}
			else
			{
				cout << -1;
			}
		}
		cout << '\n';
	}

	return 0;
}