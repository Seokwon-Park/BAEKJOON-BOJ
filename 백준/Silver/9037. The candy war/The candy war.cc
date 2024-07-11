#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			if (v[i] % 2)
				v[i]++;
		}

		if (count(v.begin(), v.end(), v[0]) == n)
		{
			cout << "0\n";
			continue;
		}

		int cycle = 0;
		while (1)
		{
			vector<int> give(n);
			for (int i = 0; i < n; i++)
			{
				give[(i + 1) % n] = v[i] / 2;
				v[i] /= 2;
			}

			for (int i = 0; i < n; i++)
			{
				v[i] += give[i];
				if (v[i] % 2)
					v[i]++;
			}

			cycle++;
			if (count(v.begin(), v.end(), v[0]) == n)
			{
				break;
			}
		}
		cout << cycle << '\n';
		
	}

	return 0;
}
