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

	int x;
	cin >> x;

	string s;
	cin >> s;

	int w = 0;
	int m = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'W') w++;
		else if (s[i] == 'M') m++;
		if (abs(w - m) > x)
		{
			if (i + 1 < s.size())
			{
				if (s[i + 1] != s[i])
				{
					if (s[i] == 'W') m++;
					else if (s[i] == 'M') w++;
					i++;
					continue;
				}
				else
				{
					if (s[i] == 'W') w--;
					else if (s[i] == 'M') m--;
					break;
				}
			}
			else
			{
				if (s[i] == 'W') w--;
				else if (s[i] == 'M') m--;
			}
		}
	}
	cout << w + m;
	return 0;
}