#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<double> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}


	double ans = DBL_MAX;
	for (int i = 0; i + k - 1 < n; i++)
	{
		for (int j = i+k; j <= n ; j++)
		{
			double sum = 0;
			for (int k = i; k < j; k++)
			{
				sum += v[k];
			}
			double m = sum / (j-i);
			double res = 0;
			for (int k = i; k < j; k++)
			{
				res += (v[k] - m) * (v[k] - m);
			}
			ans = min(ans, sqrt(res / (j-i)));
		}
		
	}
	cout << fixed;
	cout.precision(6);
	cout << ans;


	return 0;
}