#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int lb[9] = { 4,11,23,40,60,77,89,96,100 };
	while (k--)
	{
		int s;
		cin >> s;
		s = s * 100 / n;
		int ix = lower_bound(lb, lb + 9, s) - lb;
		cout << ix + 1 << ' ';
	}


	return 0;
}