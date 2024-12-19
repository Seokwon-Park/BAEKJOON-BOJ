#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[100005];
int n, x;

int check(int k)
{
	int res = 0;
	if (k == 0)
	{
		if (v[k] < v[k + 1])
		{
			res = v[k] + x - v[k + 1];
		}
		else
		{
			res = v[k + 1] + x - v[k];
		}
	}
	else if (k == n - 1)
	{
		if (v[k] < v[k - 1])
		{
			res = v[k] + x - v[k - 1];
		}
		else
		{
			res = v[k - 1] + x - v[k];
		}
	}
	else
	{
		if (v[k - 1] <= v[k] && v[k + 1] <= v[k])
		{
			res = max(v[k - 1], v[k + 1]) + x - v[k];
		}
		else if (v[k - 1] > v[k] && v[k + 1] > v[k])
		{
			res = v[k] + x - v[k - 1] + v[k] + x - v[k + 1];
		}
		else if (v[k - 1] <= v[k] && v[k + 1] > v[k])
		{
			res += max(0, v[k - 1] + x - v[k]);
			res += max(0, max(v[k - 1] + x, v[k]) + x - v[k + 1]);
		}
		else if (v[k + 1] <= v[k] && v[k - 1] > v[k])
		{
			res += max(0, v[k + 1] + x - v[k]);
			res += max(0, max(v[k + 1] + x, v[k]) + x - v[k - 1]);
		}
	}
	return max(0, res);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, check(i));
	}

	cout << ans;

	return 0;
}