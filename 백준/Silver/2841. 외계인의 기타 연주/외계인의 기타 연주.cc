#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

map<int, stack<int>> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		while (!s[a].empty() && s[a].top() > b)
		{
			ans++;
			s[a].pop();
		}
		if (!s[a].empty())
		{
			if (s[a].top() == b)
				continue;
			else
			{
				s[a].push(b);
				ans++;
			}
		}
		else
		{
			s[a].push(b);
			ans++;
		}
	}

	cout << ans;

	return 0;
}