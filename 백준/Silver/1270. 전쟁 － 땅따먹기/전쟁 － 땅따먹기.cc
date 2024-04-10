#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		map<ll, int> m;
		int t;
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			ll tmp;
			cin >> tmp;
			m[tmp]++;
		}
		auto mx = max_element(m.begin(), m.end(), [](const auto& a, const auto& b)
			{
				return a.second < b.second;
			});
		if (mx->second > t/2)
		{
			cout << mx->first;
		}
		else
		{
			cout << "SYJKGW";
		}

		cout << '\n';
	}

	return 0;
}