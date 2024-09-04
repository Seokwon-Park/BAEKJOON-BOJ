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

	int l, t;
	cin >> l >> t;
	int n;
	cin >> n;

	if (t >= l * 2)
	{
		t %= l * 2;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int loc;
		char dir;
		cin >> loc >> dir;
		int togo = t;
		if (togo >= l)
		{
			loc = l - loc;
			togo %= l;
			dir = (dir == 'D' ? 'L' : 'D');
		}
		if (dir == 'L')
		{
			if (togo <= loc)
				ans.push_back(loc - togo);
			else
				ans.push_back(togo - loc);
		}
		else
		{
			if (loc + togo <= l)
				ans.push_back(loc + togo);
			else
				ans.push_back(l - (togo - (l - loc)));
		}
	}
	sort(ans.begin(), ans.end());
	for (int i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}