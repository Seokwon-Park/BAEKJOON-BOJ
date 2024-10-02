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
	stack<pii> s;
	s.push({ 0, 0 });
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		while(m < s.top().first)
		{
			auto [h,ix] = s.top();
			s.pop();
			ans = max(ans, (i - s.top().second-1)*h);
		}
		s.push({ m, i });
	}

	while (s.size()>1)
	{
		auto [h, ix] = s.top();
		s.pop();
		ans = max(ans, (n+1 - s.top().second - 1) * h);
	}

	cout << ans;

	return 0;
}