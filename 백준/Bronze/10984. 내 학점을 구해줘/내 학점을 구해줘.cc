#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
		int total = 0;
		double totg = 0.0;
		for (int i = 0; i < n; i++)
		{
			int c;
			double g;
			cin >> c >> g;
			total += c;
			totg += c * g;
		}
		cout << fixed;
		cout.precision(1);
		cout << total << ' ' << totg / total << '\n';
	}
	
	return 0;
}