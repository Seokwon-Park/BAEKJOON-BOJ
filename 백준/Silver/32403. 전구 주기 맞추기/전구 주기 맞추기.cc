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

	int n, t;
	cin >> n >> t;
	vector<int> d;
	for (int i = 1; i * i <= t; i++)
	{
		if (t % i == 0)
		{
			if (t / i == i)
			{
				d.push_back(i);
			}
			else
			{
				d.push_back(i);
				d.push_back(t / i);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		int mn = INF;
		for (int j = 0; j < d.size(); j++)
		{
			mn = min(abs(x - d[j]), mn);
		}
		ans += mn;
	}
	cout << ans;
	
	return 0;
}