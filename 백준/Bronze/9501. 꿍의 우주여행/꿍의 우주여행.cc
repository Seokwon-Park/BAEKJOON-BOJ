#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

map<double, double> d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, d;
		cin >> n >> d;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int v, f, c;
			cin >> v >> f >> c;
			if (v * f / c >= d)
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}