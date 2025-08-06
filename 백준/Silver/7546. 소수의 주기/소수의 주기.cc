#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

ll toNum(string x, ll b)
{
	ll res = 0;
	ll exp = 1;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		if (x[i] >= '0' && x[i] <= '9')
		{
			res += (x[i] - '0') * exp;
		}
		else
		{
			res += (tolower(x[i]) - 'a' + 10) * exp;
		}
		exp *= b;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		ll b;
		string x, y;
		cin >> b >> x >> y;
		ll xnum = toNum(x, b);
		ll ynum = toNum(y, b);
		xnum %= ynum;
		
		Hash<ll, ll> remainder;
		ll loc = 1;
		cout << "Scenario #" << i << ":\n";
		while (xnum != 0)
		{
			xnum *= b;
			xnum %= ynum;
			if (remainder.find(xnum) != remainder.end())
			{
				cout << loc - remainder[xnum];
				break;
			}
			remainder[xnum] = loc++;
		}
		if (xnum == 0)
		{
			cout << 0;
		}
		cout << "\n\n";
	}


	return 0;
}
