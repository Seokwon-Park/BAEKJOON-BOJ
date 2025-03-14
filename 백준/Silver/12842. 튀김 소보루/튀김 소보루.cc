#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ll n, s;
int m;
int v[100005];

bool solve(int mid)
{
	ll result = 0;
	for (int i = 0; i < m; i++)
	{
		result += mid / v[i] + 1;
	}
	return result >= (n - s);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> s;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}

	int st = 0;
	int en = 100005;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid + 1;
		}
	}

	int result = 0;
	if (st != 0)
	{
		for (int i = 0; i < m; i++)
		{
			result += (st - 1) / v[i] + 1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (st % v[i] == 0)
		{
			result++;
		}
		if (result == n - s)
		{
			cout << i + 1;
			break;
		}
	}


	return 0;
}