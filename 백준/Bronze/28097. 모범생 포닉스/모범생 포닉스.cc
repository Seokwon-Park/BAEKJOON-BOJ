#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int total = (n - 1) * 8;
	while (n--)
	{
		int m;
		cin >> m;
		total += m;
	}
	int d = total / 24;
	int h = total % 24;
	cout << d << ' ' << h;

	return 0;
}