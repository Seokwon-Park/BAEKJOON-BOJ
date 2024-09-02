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

	int n;
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ans = INF;
	for (int i = 0; i <= 83; i++)
	{
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (v[j] < i)
			{
				res += (i - v[j]) * (i - v[j]);
			}
			if (v[j] > i + 17)
			{
				res += (v[j] - i - 17) * (v[j] - i - 17);
			}
		}
		ans = min(ans, res);
	}
	cout << ans;

	return 0;
}
