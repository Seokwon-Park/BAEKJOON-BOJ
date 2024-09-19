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
	
	int s, n;
	cin >> s >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int k, l;
	cin >> k >> l;

	int ans = INF;
	int ansnum = -1;
	for (int i = 0; i < n; i++)
	{
		int e = v[i];
		int dist = abs(e - s);
		if (dist <= k * 2)
		{
			if (ans > k * 2 - dist)
			{
				ans = k * 2 - dist;
				ansnum = i + 1;
			}
		}
		else
		{
			if (ans > (dist - k * 2) * l)
			{
				ans = (dist - k * 2) * l;
				ansnum = i + 1;
			}
		}
	}

	cout << ans << ' ' << ansnum;

	return 0;
}
