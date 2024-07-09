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

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		int res = 0;
		for (int i = 0; i < 16; i++)
		{
			if (i % 2 == 0)
			{
				int n = s[i] - '0';
				n *= 2;
				if (n >= 10)
				{
					n = n / 10 + n % 10;
				}
				res += n;
			}
			else
			{
				res += s[i] - '0';
			}
		}
		if (res % 10 == 0)
			cout << "T";
		else
			cout << "F";
		cout << '\n';
	}
	return 0;
}