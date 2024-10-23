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

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		if (n > 15)
		{
			n -= 15;
			int cur = 15;
			int row = (n - 1) / 14;
			int left = (n - 1) % 14 + 1;
			if (row % 2 == 0)
			{
				n = 15 - left;
			}
			else
			{
				n = 1 + left;
			}
		}

		string s;
		while (n)
		{
			s = (char)((n % 2) + '0') + s;
			n /= 2;
		}
		s = string(4 - s.size(), '0') + s;

		for (int i = 0; i < 4; i++)
		{
			if (s[i] == '0')
			{
				cout << "V";
			}
			else
			{
				cout << "딸기";
			}
		}
		cout << '\n';
	}



	return 0;
}