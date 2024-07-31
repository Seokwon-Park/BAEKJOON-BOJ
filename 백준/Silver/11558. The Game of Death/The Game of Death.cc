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
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}

		int cur = 1;
		int k = 0;
		
		while (1)
		{
			k++;
			cur = v[cur];
			if (cur == n)
				break;
			if (k > n)
			{
				break;
			}
		}
		if (k > n)
		{
			cout << 0;
		}
		else
		{
			cout << k;
		}
		cout << '\n';
	}
	return 0;
}