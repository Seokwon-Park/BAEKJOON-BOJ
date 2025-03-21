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
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x * x + y * y, i };
	}
	stable_sort(v.begin(), v.end(), [](auto a, auto b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first > b.first;
		});
	
	for (auto [x, y] : v)
		cout << y+1 << '\n';

	return 0;
}