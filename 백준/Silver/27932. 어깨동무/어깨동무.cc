#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, k;
int v[1000005];
bool tired[1000005];

bool solve(int x)
{
	fill(tired, tired + n, 0);
	int res = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (abs(v[i] - v[i + 1]) > x)
		{
			if (!tired[i])
			{
				tired[i] = 1;
				res++;
			}
			if (!tired[i + 1])
			{
				tired[i + 1] = 1;
				res++;
			}
		}
	}

	return res <= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int st = -1;
	int en = INF;
	
	while (st +1  < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid;
		}
	}
	cout << en;

	return 0;
}