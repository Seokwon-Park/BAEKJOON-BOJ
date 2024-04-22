#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h;
	cin >> w >> h;
	int n;
	cin >> n;
	vector<pii> shop;
	for (int i = 0; i < n; i++)
	{
		int d, l;
		cin >> d >> l;
		shop.push_back({ d,l });
	}
	int dir, loc;
	cin >> dir >> loc;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [d, l] = shop[i];
		if (d == dir) // 같은 면일때
			ans += abs(loc - l);
		else if (dir == 1) // 북
		{
			if (d == 2) // 남
			{
				ans += min(l + loc, w - l + w - loc) + h;
			}
			else if (d == 3) // 서
			{
				ans += loc + l;
			}
			else if (d == 4)
			{
				ans += w - loc + l;
			}
		}
		else if (dir == 2) // 남
		{
			if (d == 1) // 북
			{
				ans += min(l + loc, w - l + w - loc) + h;
			}
			else if (d == 3) // 서
			{
				ans += loc + h - l;
			}
			else if (d == 4) // 동
			{
				ans += w - loc + h - l;
			}
		}
		else if (dir == 3) // 서
		{
			if (d == 1) // 북
			{
				ans += loc + l;
			}
			else if (d == 2) // 남
			{
				ans += h - loc + l;
			}
			else if (d == 4)
			{
				ans += min(loc + l, h - loc + h - l) + w;
			}
		}
		else if (dir == 4) // 동
		{
			if (d == 1) // 북
			{
				ans += loc + w - l;
			}
			else if (d == 2) // 남
			{
				ans += h - loc + w - l;
			}
			else if (d == 3) // 서
			{
				ans += min(loc + l, h - loc + h - l) + w;
			}
		}
	}
	cout << ans;


	return 0;
}
