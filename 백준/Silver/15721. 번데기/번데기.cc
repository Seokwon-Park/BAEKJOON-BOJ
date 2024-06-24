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

	int n = 2;
	
	int bcall = 0;
	int dcall = 0;

	int a;
	cin >> a;
	int t;
	cin >> t;
	int bd;
	cin >> bd;

	int cur = 0;
	while (true)
	{
		string s = "0101" + string(n, '0') + string(n, '1');

		for (auto c : s)
		{
			if (c == '0')
				bcall++;
			else if (c == '1')
				dcall++;

			if (bd == 0 && bcall == t)
			{
				cout << cur;
				return 0;
			}
			else if (bd == 1 && dcall == t)
			{
				cout << cur;
				return 0;
			}
			cur++;
			cur %= a;
		}
		n++;
	}

	return 0;
}
