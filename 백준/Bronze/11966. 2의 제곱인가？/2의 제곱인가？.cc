#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cmp = 1;
	while (cmp <= n)
	{
		if (cmp == n)
		{
			cout << 1;
			return 0;
		}
		cmp <<= 1;
	}
	cout << 0;

	return 0;
}