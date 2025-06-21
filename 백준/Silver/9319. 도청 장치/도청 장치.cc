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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int B;
		cin >> B;
		double x, y;
		cin >> x >> y;
		vector<double> r(n);
		double rsum = 0;
		for (int i = 0; i < n; i++)
		{
			double xi, yi, si;
			cin >> xi >> yi >> si;
			double xx = x - xi;
			double yy = y - yi;
			r[i] = si / (xx * xx + yy * yy);
			rsum += r[i];
		}

		bool find = false;
		for (int i = 0; i < n; i++)
		{
			double res = 6 * (B + rsum - r[i]);
			if (r[i] > res)
			{
				cout << i + 1;
				find = true;
				break;
			}
		}
		if (!find)
		{
			cout << "NOISE";
		}
		cout << '\n';
	}


	return 0;
}
