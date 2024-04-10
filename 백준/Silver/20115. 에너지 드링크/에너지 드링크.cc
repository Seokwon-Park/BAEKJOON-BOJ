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
	vector<double> v(n);
	for (auto& d : v)
		cin >> d;

	sort(v.begin(), v.end());

	double ans = v[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		ans += v[i] / 2;
	}

	cout << fixed;
	cout.precision(5);
	cout << ans;


	return 0;
}