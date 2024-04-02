#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<double> v(n);
	for (auto& i : v)
		cin >> i;

	sort(v.begin(), v.end());
	for (int i = 0; i < 7; i++)
	{
		cout << fixed;
		cout.precision(3);
		cout << v[i] << '\n';
	}

	return 0;
}