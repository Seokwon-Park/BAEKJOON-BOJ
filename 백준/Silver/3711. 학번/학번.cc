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

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int m = 1;
		while (1)
		{
			vector<bool> isExist(m, false);
			bool canAnswer = true;
			for (int i = 0; i < n; i++)
			{
				int res = v[i] % m;
				if (isExist[res])
				{
					canAnswer = false;
					break;
				}
				else
				{
					isExist[res] = true;
				}
			}
			if (canAnswer)
			{
				break;
			}
			
			m++;
		}
		cout << m << '\n';
	}

	return 0;
}