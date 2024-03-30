#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	double total = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		string a, c;
		double b;
		cin >> a >> b >> c;
		double d;
		if (c.size() == 1)
			d = 0.0;
		else
			d = 4.0 - (c[0] - 'A') + (c[1] == '+' ? 0.3 : c[1] == '-' ? -0.3 : 0.0);
		//cout << d << '\n';
		total += d * b;
		sum += b;
	}
	cout << fixed;
	cout.precision(2);
	double ans = total / sum;
	ans += 0.0000000000001;
	cout << ans;

	return 0;
}