#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;
	bool dir = 0;
	int x = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		if (x == 0)
			x = b;
		else
			x = x / a * b;
		if (s == 1)
			dir = !dir;
	}
	cout << dir << ' ' << x;

	return 0;
}