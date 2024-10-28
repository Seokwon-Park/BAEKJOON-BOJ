#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		ans += v[i];
	}
	sort(v.begin(), v.end());
	if (ans % 2 == 0)
	{
		cout << ans;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i] % 2 == 1)
			{
				ans -= v[i];
				break;
			}
		}
		cout << ans;
	}

	return 0;
}