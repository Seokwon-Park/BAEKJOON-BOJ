#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, m;
	cin >> x >> y >> m;

	vector<int> enemy(x);
	vector<int> heal(y);
	ll totald = 0;
	ll totalh = m;
	for (int& i : enemy)
	{
		cin >> i;
		totald += i;
	}

	for (int& i : heal)
	{
		cin >> i;
		totalh += i;
	}

	if (totalh <= totald)
	{
		cout << 0;
	}
	else
	{
		int cure = 0;
		int curh = 0;
		int hp = m;
		while (cure < x || curh < y)
		{
			if (curh < y && hp <= m / 2)
			{
				cout << curh + 1 << '\n';
				hp += heal[curh++];
			}
			else if (cure < x)
			{
				cout << -(cure + 1) << '\n';
				hp -= enemy[cure++];
			}
			else
			{
				cout << curh + 1 << '\n';
				curh++;
			}

		}
	}


	return 0;
}