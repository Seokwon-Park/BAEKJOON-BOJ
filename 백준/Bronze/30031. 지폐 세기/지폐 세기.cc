#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (a == 136)
			res += 1000;
		else if (a == 142)
			res += 5000;
		else if (a == 148)
			res += 10000;
		else
			res += 50000;
	}
	cout << res;

	return 0;
}