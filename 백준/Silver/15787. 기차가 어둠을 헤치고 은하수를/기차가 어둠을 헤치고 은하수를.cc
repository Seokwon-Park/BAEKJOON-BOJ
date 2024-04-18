#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bitset<20> train[100005];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int j, x;
			cin >> j >> x;
			train[j][x - 1] = 1;
		}
		else if (cmd == 2)
		{
			int j, x;
			cin >> j >> x;
			train[j][x - 1] = 0;
		}
		else if (cmd == 3)
		{
			int j;
			cin >> j;
			train[j] <<= 1;
		}
		else
		{
			int j;
			cin >> j;
			train[j] >>= 1;
		}
	}

	set<ll> s;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ll res = train[i].to_ullong();
		if (s.find(res) == s.end())
		{
			s.insert(res);
			ans++;
		}
	}
	cout << ans;

	return 0;
}