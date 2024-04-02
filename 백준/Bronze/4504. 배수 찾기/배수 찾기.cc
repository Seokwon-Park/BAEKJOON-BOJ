#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (1)
	{
		int m;
		cin >> m;
		if (m == 0)break;
		if (m % n == 0)
			cout << m << " is a multiple of " << n << '.';
		else
			cout << m << " is NOT a multiple of " << n << '.';
		cout << '\n';
	}
	return 0;
}