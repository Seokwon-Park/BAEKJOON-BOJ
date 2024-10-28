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
	vector<pii> v;
	int pre = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a >= b)
		{
			pre++;
		}
		else
		{
			v.push_back({ a,b });
		}
	}
	if (pre >= k)
	{
		cout << 0;
		return 0;
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			int ares = a.second - a.first;
			int bres = b.second - b.first;
			return ares < bres;
		}
	);

	int off = k - pre - 1;
	cout << v[off].second - v[off].first;


	return 0;
}