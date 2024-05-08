#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1000; i <= 9999; i++)
	{
		int res = 0;
		int tmp = i;
		while (tmp)
		{
			res += tmp % 10;
			tmp /= 10;
		}

		tmp = i;
		int res2 = 0;
		while (tmp)
		{
			res2 += tmp % 12;
			tmp /= 12;
		}
		if (res != res2) continue;

		tmp = i;
		int res3 = 0;
		while (tmp)
		{
			res3 += tmp % 16;
			tmp /= 16;
		}
		if (res != res3) continue;
		cout << i << '\n';
	}

	return 0;
}