// reference https://www.mathopenref.com/coordpolygonarea2.html
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<double,double>> v(n);
	int prev = n - 1;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}

	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (v[i].first + v[prev].first) * (v[i].second - v[prev].second);
		prev = i;
	}

	cout << fixed << setprecision(1);
	cout << abs(ans / 2.0);

	return 0;
}