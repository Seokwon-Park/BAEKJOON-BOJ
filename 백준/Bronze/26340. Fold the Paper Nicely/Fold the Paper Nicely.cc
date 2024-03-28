#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		cout << "Data set: " << a << ' ' << b << ' ' << n << '\n';
		for (int i = 0; i < n; i++)
		{
			if (a > b)
			{
				a /= 2;
			}
			else
			{
				b /= 2;
			}
		}
		if (a < b)
			swap(a, b);
		cout << a << ' ' << b << '\n';
		cout << '\n';
	}

	return 0;
}