#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int res = 0;
	int mul = 1;
	int k = 0;
	for (auto c : s)
	{
		if (c != '*')
		{
			res += (c - '0') * mul;
		}
		else
		{
			k = mul;
		}
		mul = (mul == 1 ? 3 : 1);
	}

	if (k == 1)
	{
		cout << (10 - (res % 10)) % 10;
	}
	else
	{
		for (int m = 0; m <= 9; m++)
		{
			if ((res + m * 3) % 10 == 0)
			{
				cout << m;
				return 0;
			}
		}
	}

	

	return 0;
}