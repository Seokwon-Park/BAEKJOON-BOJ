#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// 1-2 2-4 3-7 4-10 5-14 6-

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, l;
		cin >> n >> m >> l;
		for (int i = 0; i < n; i++)
		{
			int s;
			cin >> s;
			if (s == -1)continue;
			if (m - s > l)
			{
				l = m - s;
			}
		}
		cout << "The scoreboard has been frozen with " << l << (l == 1 ?" minute remaining." : " minutes remaining.") << '\n';
	}
	

	return 0;
}