#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

pii keyloc[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s = "qwertyuiop";
	for (int i = 0; i < 10; i++)
	{
		keyloc[s[i]] = { i, 0 };
	}
	s = "asdfghjkl";
	for (int i = 0; i < 9; i++)
	{
		keyloc[s[i]] = { i, 1 };
	}
	s = "zxcvbnm";
	for (int i = 0; i < 7; i++)
	{
		keyloc[s[i]] = { i, 2 };
	}
	
	char l, r;
	cin >> l >> r;

	auto [lx,ly] = keyloc[l];
	auto [rx,ry] = keyloc[r];

	string str;
	cin >> str;
	int ans = 0;
	for (auto c : str)
	{
		auto [x, y] = keyloc[c];

		if (x >= 5 || (x == 4 && y == 2))
		{
			ans += abs(x - rx) + abs(y - ry);
			rx = x;
			ry = y;
		}
		else
		{
			ans += abs(x - lx) + abs(y - ly);
			lx = x;
			ly = y;
		}
		ans++;
	}

	cout << ans;

	return 0;
}
