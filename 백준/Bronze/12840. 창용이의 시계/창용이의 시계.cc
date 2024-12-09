#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int h, m, s;

void UpdateHMS(int amount)
{
	int tmp = s + m * 60 + h * 3600;
	tmp += amount;
	while (tmp < 0)
	{
		tmp += 3600 * 24;
	}

	h = tmp / 3600;
	tmp %= 3600;
	m = tmp / 60;
	tmp %= 60;
	s = tmp;
	h %= 24;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> m >> s;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		if (t == 1 || t == 2)
		{
			int c;
			cin >> c;
			UpdateHMS((t%2 == 1?c:-c));
		}
		else
		{
			cout << h << ' ' << m << ' ' << s << '\n';
		}
	}




	return 0;
}