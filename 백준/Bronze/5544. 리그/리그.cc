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
	int vs = n * (n - 1) / 2;

	vector<int> v(n + 1, 0);

	for (int i = 0; i < vs; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c == d)
		{
			v[a]++;
			v[b]++;
		}
		else if (c > d)
			v[a] += 3;
		else
			v[b] += 3;

	}

	vector<pii> sc;
	for (int i = 1; i <= n; i++)
	{
		sc.push_back({ v[i], i });
	}
	sort(sc.begin(), sc.end(), greater<pii>());

	int cursc = -1;
	int curRank = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		if (cursc != sc[i].first)
		{
			cursc = sc[i].first;
			curRank = i+1;
			ans[sc[i].second - 1] = i+1;
		}
		else
		{
			cursc = sc[i].first;
			ans[sc[i].second - 1] = curRank;
		}
	}
	for (auto i : ans)
		cout << i << '\n';

	return 0;
}