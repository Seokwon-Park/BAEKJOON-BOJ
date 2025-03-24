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
	
	unordered_map<int, unordered_map<int, bool>> m;
	vector<pii> v;
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		m[x][y] = true;
		v.push_back({ x,y });
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = v[i];
		if (m[x + a][y] && m[x][y + b] && m[x + a][y + b])
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}