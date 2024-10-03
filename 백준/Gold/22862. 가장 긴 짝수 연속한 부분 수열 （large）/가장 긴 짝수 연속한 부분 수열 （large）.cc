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

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	if (n == 1)
	{
		cout << (v[0] % 2 == 0);
		return 0;
	}
	int st = 0;
	while (st < n && v[st] % 2 != 0)
		st++;
	if (st >= n)
	{
		cout << 0;
		return 0;
	}
	int en = st;
	int odd = 0;
	int ans = 1;
	while (st< n && en+1 < n)
	{
		en++;
		odd += (v[en] % 2 == 1);
		if (odd <= k)
		{
			ans = max(ans, en - st + 1-odd);
		}
		else
		{
			if (st + 1 < n)
			{
				st++;
			}
			while (st < n && v[st] % 2 != 0)
			{
				odd--;
				st++;
			}
		}
	}
	cout << ans;



	return 0;
}