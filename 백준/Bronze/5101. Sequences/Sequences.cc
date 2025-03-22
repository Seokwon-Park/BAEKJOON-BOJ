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

	while (true)
	{
		int a, d, chk;
		cin >> a >> d >> chk;
		if (a == 0 && d == 0 && chk == 0)
		{
			break;
		}
		if ((chk - a) / d < 0 || (chk-a)%d != 0)
		{
			cout << 'X';
		}
		else
		{
			cout << (chk - a) / d + 1;
		}
		cout << '\n';
		

	}

	return 0;
}
