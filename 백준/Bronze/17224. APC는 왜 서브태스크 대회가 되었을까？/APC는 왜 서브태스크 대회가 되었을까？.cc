#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, k;
	cin >> n >> l >> k;
	int res1 = 0;
	int res2 = 0;
	for (int i = 0; i < n; i++)
	{
		int s1, s2;
		cin >> s1 >> s2;
		if (s2 <= l)
			res2++;
		else if (s1 <= l)
			res1++;
	}
	int ans = 0;
	if (k >= res2)
	{
		ans += 140 * res2;
		k -= res2;
	}
	else
	{
		ans += 140 * k;
		k = 0;
	}
	if (k >= res1)
	{
		ans += 100 * res1;
		k -= res1;
	}
	else
	{
		ans += 100 * k;
		k = 0;
	}

	cout << ans;


	return 0;
}