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
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	
	sort(v.begin(), v.end());

	int cur = 0;
	int curex = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [a, b] = v[i];
		while (b > 0)
		{
			if (cur < a)
			{
				if ((cur + 1) % 7 == 6)
				{
					cur += 2;
					continue;
				}
				cur++;
			}
			else
			{
				if (curex + 1 > a)
				{
					cout << -1;
					return 0;
				}
				curex++;
				ans++;
			}
			b--;
		}
	}
	cout << ans;

	return 0;
}