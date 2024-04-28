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
	string s;
	cin >> s;

	int l = 0;
	while (l < n && s[l] == s[0])l++;
	int r = n - 1;
	int rlen = 0;
	while (r >= 0 && s[r] == s[n - 1])
	{
		r--;
		rlen++;
	}

	int red = 0;
	int blue = 0;
	for (int i = l; i <= r; i++)
	{
		if (s[i] == 'R')
			red++;
		else
			blue++;
	}

	int ans = 0;
	if (s[0] == s[n - 1])
	{
		if (l == rlen && l == n)
		{
			ans = 0;
		}
		else if (s[0] == 'R')
		{
			if (l > rlen)
			{
				ans = min(red + rlen, blue);
			}
			else
			{
				ans = min(red + l, blue);
			}
		}
		else if (s[0] == 'B')
		{
			if (l > rlen)
			{
				ans = min(blue + rlen, red);
			}
			else
			{
				ans = min(blue + l, red);
			}
		}
	}
	else
	{
		if (l + rlen == n)
			ans = 0;
		else
			ans = min(red, blue);
	}
	cout << ans;



	return 0;
}