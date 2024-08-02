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
	vector<int> poly(1, 0);

	bool isNeg = 0;
	string coef = "";
	for (char c : s)
	{
		if (isdigit(c))
		{
			coef += c;
		}
		else
		{
			if (c == 'x')
			{
				if (coef.empty())
				{
					cout << (isNeg ? -1 : 1);
				}
				else
				{
					int res = stoi(coef);
					cout << (isNeg ? -res : res);
				}
				return 0;
			}
			if (c == '+')
			{
				coef = "";
				isNeg = false;
			}
			if (c == '-')
			{
				coef = "";
				isNeg = true;
			}
		}
	}
	cout << 0;
	return 0;
}