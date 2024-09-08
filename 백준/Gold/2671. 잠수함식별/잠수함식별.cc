#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int ix = 0;
	while (ix < s.size())
	{
		if (s[ix] == '0')
		{
			if (ix+1 < s.size() && s[ix+1] == '1')
			{
				ix += 2;
			}
			else
			{
				cout << "NOISE";
				return 0;

			}
		}
		else if (s[ix] == '1')
		{
			if (ix + 2 < s.size() && s[ix + 1] == '0' && s[ix + 2] == '0')
			{
				ix += 3;
				while (s[ix] == '0')
					ix++;
			}
			else
			{
				cout << "NOISE";
				return 0;
			}
			if (s[ix] == '1')
			{
				ix++;
				while (s[ix] == '1')
				{
					if (ix + 2 < s.size() && s[ix + 1] == '0' && s[ix + 2] == '0')
					{
						break;
					}
					ix++;
				}
			}
			else
			{
				cout << "NOISE";
				return 0;

			}
		}
	}

	cout << "SUBMARINE";


	return 0;
}
