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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int st = 0;
	int en = 0;
	int cnt = v[st] % 2;
	int ans = 0;
	while (true)
	{
		if (cnt <= k)
		{
			ans = max(ans, en - st + 1 - cnt);
			en++;
			if (en >= n)
			{
				ans = max(ans, en - st - cnt);
				break;
			}
			cnt += v[en] % 2;
		}
		else
		{
			cnt -= v[st] % 2;
			st++;
		}
	}

	cout << ans;

	return 0;
}



