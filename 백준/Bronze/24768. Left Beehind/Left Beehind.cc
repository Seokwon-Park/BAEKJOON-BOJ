#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	while (cin >> x >> y)
	{
		if (x == 0 && y == 0)
		{
			break;
		}
		if (x + y == 13)
		{
			cout << "Never speak again.";
		}
		else if (x < y)
		{
			cout << "Left beehind.";
		}
		else if (x == y)
		{
			cout << "Undecided.";
		}
		else
		{
			cout << "To the convention.";
		}
		cout << '\n';
	}
	return 0;
}